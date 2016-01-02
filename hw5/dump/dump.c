#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>
#include <linux/printk.h>
#include <linux/types.h>

//#define COMMAND_LINE_SIZE 2048

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Hao Wang");

extern char __initdata boot_command_line[];
extern char *saved_command_line;

static int __init dump_init(void)
{
	printk(KERN_DEBUG "boot_command_line:\n");
	print_hex_dump(KERN_DEBUG, "mem: ", DUMP_PREFIX_ADDRESS, 
			8, 1, boot_command_line, strlen(boot_command_line), 1);
	printk(KERN_DEBUG "saved_command_line:\n");
	print_hex_dump(KERN_DEBUG, "mem: ", DUMP_PREFIX_ADDRESS, 
			8, 1, saved_command_line, strlen(saved_command_line), 1);
	return 0;
}

static void __exit dump_exit(void)
{
}

module_init(dump_init);
module_exit(dump_exit);

