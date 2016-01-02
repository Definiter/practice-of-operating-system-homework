#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

int init_module(void)
{
	float a = 2.718;
	printk(KERN_INFO "float: %lf\n", a);
        return 0;
}

void cleanup_module(void)
{
}

