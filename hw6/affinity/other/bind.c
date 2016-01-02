/*
 *  bind.c
 *
 *  bind a user's processes to a cpu through
 *    1). scanning existing processes and bind them;
 *    2). modify syscall 'execve' to bind newly forked processes.
 */

/*
 * Copyright (C) 2015 by Shuyang Shi
 */

/*
 * The necessary header files
 */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/unistd.h>
#include <linux/syscalls.h>
#include <linux/delay.h>
#include <asm/cacheflush.h>
/*
 * For the current (process) structure, we need
 * this to know who the current user is.
 */
#include <linux/sched.h>
#include <linux/uaccess.h>

/*
 * Write Protect Bit (CR0:16)
 */
#define CR0_WP 0x00010000

/*
 * Place of sys_execve based on sys_call_table
 * Attention: cannot use __NR_execve becuse
 * it refers to to place of stub_execve.
 * Actually, the call chain is
 * sys_call_table[__NR_execve]
 * -> stub_execve
 * -> sys_execve
 * -> do_execve
 */
#define NR_sys_execve 11

/*
 * The system call table (a table of functions).
 */
static void **sys_call_table;

void acquire_sys_call_table(void)
{
unsigned long ptr;
unsigned long *p;

for (ptr = (unsigned long)sys_close;
ptr < (unsigned long)&loops_per_jiffy;
ptr += sizeof(void *)) {
p = (unsigned long *)ptr;
if (p[__NR_close] == (unsigned long)sys_close) {
pr_info("Found the sys_call_table!!!\n");
sys_call_table = (void **)p;
return;
}
}
sys_call_table = NULL;
}

/*
 * UID we want to bind - will be filled from the
 * command line
 */
static int uid = 1001;
module_param(uid, int, 0644);

/*
 * CPUID we want to bind the user to - will be filled
 * from the command line
 */
static int mycpuid = 1;
module_param(mycpuid, int, 0644);

/*
 * function to set affinity
 */
extern long sched_setaffinity(pid_t, const struct cpumask *);

/*
 * A pointer to the original system call. The reason
 * we keep this, rather than call the original function
 * is because somebody else might have
 * replaced the system call before us. Note that this
 * is not 100% safe, because if another module
 * replaced sys_open before us, then when we're inserted
 * we'll call the function in that module - and it
 * might be removed before we are.
 *
 * Another reason for this is that we can't get sys_open.
 * It's a static variable, so it is not exported.
 */

asmlinkage long (*original_call_execve)(const char __user *,
        const char __user *const __user *,
        const char __user *const __user *);

asmlinkage long our_sys_execve(const char __user *filename,
        const char __user *const __user *argv,
        const char __user *const __user *envp)
{
        struct cpumask mask;
        if (uid == current_uid().val) {
cpumask_clear(&mask);
        cpumask_set_cpu(mycpuid, &mask);
if (sched_setaffinity(current->pid, &mask))
printk("Cannot set PID %d to CPU %d\n", current->pid, mycpuid);
}
        return original_call_execve(filename, argv, envp);
}


/*
 * Initialize the module - replace the system call
 */
int init_module(void)
{
unsigned long cr0;
struct cpumask mask;
struct task_struct *task;

/*
* Warning - too late for it now, but maybe for
* next time…
*/
pr_alert("I'm dangerous. I hope you did a ");
pr_alert("sync before you insmod'ed me.\n");
pr_alert("My counterpart, cleanup_module(), is even");
pr_alert("more dangerous. If\n");
pr_alert("you value your file system, it will ");
pr_alert("be \"sync; rmmod\"\n");
pr_alert("when you remove this module.\n");

/*
* Scan all existing processes and
* bind all that belong to user uid
* to a certain CPU
*/
cpumask_set_cpu(mycpuid, &mask);
for_each_process(task)
if (task_uid(task).val == uid)
sched_setaffinity(task->pid, &mask);

/*
* Acquire syscall table
*/
acquire_sys_call_table();
if (!sys_call_table) {
pr_info("Cannot find the system call table!\n");
return -1;
}

/*
* Keep a pointer to the original function in
* original_call, and then replace the system call
* in the system call table with our_sys_open
*/
cr0 = read_cr0();
write_cr0(cr0 & ~CR0_WP);

original_call_execve = sys_call_table[NR_sys_execve];
sys_call_table[NR_sys_execve] = our_sys_execve;

write_cr0(cr0);

/*
* To get the address of the function for system
* call foo, go to sys_call_table[__NR_foo].
*/

pr_info("Binding UID: %d\n", uid);

return 0;
}

/*
 * Cleanup - unregister the appropriate file from /proc
 */
void cleanup_module(void)
{
unsigned long cr0;

/*
* Return the system call back to normal
*/
if (sys_call_table[__NR_execve] != our_sys_execve) {
pr_alert("Somebody else also played with the ");
pr_alert("open system call\n");
pr_alert("The system may be left in ");
pr_alert("an unstable state.\n");
}

cr0 = read_cr0();
write_cr0(cr0 & ~CR0_WP);

sys_call_table[NR_sys_execve] = original_call_execve;

write_cr0(cr0);
}

/*
 * Get rid of taint message by declaring code as GPL.
 */
MODULE_LICENSE("GPL");
