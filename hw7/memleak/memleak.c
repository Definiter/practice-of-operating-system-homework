#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>

int init_module(void)
{
	int *leak = (int *)kmalloc(42 * sizeof(int), GFP_KERNEL);
	int i;
	for (i = 0; i < 42; i++)
		leak[i] = i;
	printk(KERN_INFO "Memory leaked.");
        return 0;
}

void cleanup_module(void)
{
}

