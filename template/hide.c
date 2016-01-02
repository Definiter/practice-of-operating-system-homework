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

int init_module(void)
{
        return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "Visibly goodbye.\n");
}

MODULE_LICENSE("GPL");
