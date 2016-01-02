#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x9dbe05f4, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xc1610756, __VMLINUX_SYMBOL_STR(kthread_stop) },
	{ 0xd028157d, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0x72a09f8b, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0xbda57782, __VMLINUX_SYMBOL_STR(queue_size) },
	{ 0x93872b8c, __VMLINUX_SYMBOL_STR(queue) },
	{ 0x12a38747, __VMLINUX_SYMBOL_STR(usleep_range) },
	{ 0xc7eda3e8, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x593251d, __VMLINUX_SYMBOL_STR(queue_tail) },
	{ 0xe92b1379, __VMLINUX_SYMBOL_STR(queue_head) },
	{ 0x5cce5e81, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x397dc3ee, __VMLINUX_SYMBOL_STR(lock) },
	{ 0xb3f7646e, __VMLINUX_SYMBOL_STR(kthread_should_stop) },
	{ 0x4f68e5c9, __VMLINUX_SYMBOL_STR(do_gettimeofday) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=producer";


MODULE_INFO(srcversion, "2EE542A4F9CA10FB5ECA776");
