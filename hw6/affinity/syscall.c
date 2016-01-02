#include <linux/kernel.h>	/* We're doing kernel work */
#include <linux/module.h>	/* Specifically, a module, */
#include <linux/moduleparam.h>	/* which will have params */
#include <linux/unistd.h>	/* The list of system calls */

/* 
 * For the current (process) structure, we need
 * this to know who the current user is. 
 */
#include <linux/sched.h>
#include <asm/uaccess.h>

/*
 * For acquiring sys_call_table
 */

#include <linux/syscalls.h>
#include <linux/delay.h>
#include <asm/paravirt.h>

#define SYSCALL_execve 11

/*
 * via https://bbs.archlinux.org/viewtopic.php?id=139406
 */
static void **acquire_sys_call_table(void) {
	unsigned long int offset = PAGE_OFFSET;
	unsigned long **sct;
	while (offset < ULLONG_MAX) {
		sct = (unsigned long **)offset;
		if (sct[__NR_close] == (unsigned long *) sys_close) 
			return (void **)sct;
		offset += sizeof(void *);
	}
	return NULL;
}

/* 
 * The system call table (a table of functions). We
 * just define this as external, and the kernel will
 * fill it up for us when we are insmod'ed
 *
 * sys_call_table is no longer exported in 2.6.x kernels.
 * If you really want to try this DANGEROUS module you will
 * have to apply the supplied patch against your current kernel
 * and recompile it.
 */
void **sys_call_table;
unsigned long original_cr0;

/* 
 * UID we want to spy on - will be filled from the
 * command line 
 */
static int uid = 1000;
module_param(uid, int, 0644);

/* 
 * UID we want to spy on - will be filled from the
 * command line 
 */
static int mycpuid = 1;
module_param(mycpuid, int, 0644);

/* 
 * A pointer to the original system call. The reason
 * we keep this, rather than call the original function
 * (sys_open), is because somebody else might have
 * replaced the system call before us. Note that this
 * is not 100% safe, because if another module
 * replaced sys_open before us, then when we're inserted
 * we'll call the function in that module - and it
 * might be removed before we are.
 *
 * Another reason for this is that we can't get sys_open.
 * It's a static variable, so it is not exported. 
 */

asmlinkage int (*original_call) (const char *, int, int);


/* Import from kernel. */
extern long sched_setaffinity(pid_t, const struct cpumask *);

/* 
 * The function we'll replace sys_open (the function
 * called when you call the open system call) with. To
 * find the exact prototype, with the number and type
 * of arguments, we find the original function first
 * (it's at fs/open.c).
 *
 * In theory, this means that we're tied to the
 * current version of the kernel. In practice, the
 * system calls almost never change (it would wreck havoc
 * and require programs to be recompiled, since the system
 * calls are the interface between the kernel and the
 * processes).
 */
asmlinkage int our_sys_execve(const char *filename, int flags, int mode)
{
	/* 
	 * Check if this is the user we're spying on 
	 */
	struct cpumask mask;
	if (uid == current->cred->uid.val) {
		cpumask_clear(&mask);
		cpumask_set_cpu(mycpuid, &mask);
		if (sched_setaffinity(current->pid, &mask))
			printk(KERN_INFO "Cannot set PID %d to CPU %d\n", current->pid, mycpuid);
		else
			printk(KERN_INFO "Set PID %d to CPU %d successfully.\n", current->pid, mycpuid);
	}



	/* 
	 * Call the original sys_open - otherwise, we lose
	 * the ability to open files 
	 */
	return original_call(filename, flags, mode);
}

/* 
 * Initialize the module - replace the system call 
 */
int init_module()
{
	/* 
	 * Warning - too late for it now, but maybe for
	 * next time... 
	 */
	printk(KERN_ALERT "I'm dangerous. I hope you did a ");
	printk(KERN_ALERT "sync before you insmod'ed me.\n");
	printk(KERN_ALERT "My counterpart, cleanup_module(), is even");
	printk(KERN_ALERT "more dangerous. If\n");
	printk(KERN_ALERT "you value your file system, it will ");
	printk(KERN_ALERT "be \"sync; rmmod\" \n");
	printk(KERN_ALERT "when you remove this module.\n");

	struct cpumask mask;
	struct task_struct *task;
	cpumask_set_cpu(mycpuid, &mask);
	for_each_process(task)
		if (task_uid(task).val == uid)
			sched_setaffinity(task->pid, &mask);

	/* get sys_call_table address */
	sys_call_table = acquire_sys_call_table();

	/* change cr0 to modify kernal memory */
	original_cr0 = read_cr0();

	write_cr0(original_cr0 & ~0x00010000);

	/* 
	 * Keep a pointer to the original function in
	 * original_call, and then replace the system call
	 * in the system call table with our_sys_execve
	 */
	original_call = sys_call_table[SYSCALL_execve];
	sys_call_table[SYSCALL_execve] = our_sys_execve;

	/* 
	 * To get the address of the function for system
	 * call foo, go to sys_call_table[__NR_foo]. 
	 */

	printk(KERN_INFO "Spying on UID:%d\n", uid);

	/* Use dump_stack to print call stack */
	printk("Call stack printed by dump_stack()\n");
	dump_stack();

	/* recover original cr0 */
	write_cr0(original_cr0);

	return 0;
}

/* 
 * Cleanup - unregister the appropriate file from /proc 
 */
void cleanup_module()
{
	/* 
	 * Return the system call back to normal 
	 */
	if (sys_call_table[SYSCALL_execve] != our_sys_execve) {
		printk(KERN_ALERT "Somebody else also played with the ");
		printk(KERN_ALERT "open system call\n");
		printk(KERN_ALERT "The system may be left in ");
		printk(KERN_ALERT "an unstable state.\n");
	}

	write_cr0(original_cr0 & ~0x00010000);
	sys_call_table[SYSCALL_execve] = original_call;
	write_cr0(original_cr0);

}

