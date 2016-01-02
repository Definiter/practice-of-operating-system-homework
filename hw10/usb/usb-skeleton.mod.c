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
	{ 0x5612d940, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x903b70bb, __VMLINUX_SYMBOL_STR(noop_llseek) },
	{ 0xaba8019, __VMLINUX_SYMBOL_STR(usb_deregister) },
	{ 0xa6a3d7f1, __VMLINUX_SYMBOL_STR(usb_register_driver) },
	{ 0x4f8b5ddb, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0xfa66f77c, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0x34f22f94, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0x26c38136, __VMLINUX_SYMBOL_STR(mutex_lock_interruptible) },
	{ 0x5dd18617, __VMLINUX_SYMBOL_STR(usb_unanchor_urb) },
	{ 0x5f834055, __VMLINUX_SYMBOL_STR(usb_anchor_urb) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0xe440e9cc, __VMLINUX_SYMBOL_STR(usb_alloc_coherent) },
	{ 0xf147ecb1, __VMLINUX_SYMBOL_STR(down_trylock) },
	{ 0xf22449ae, __VMLINUX_SYMBOL_STR(down_interruptible) },
	{ 0xa18ccca, __VMLINUX_SYMBOL_STR(usb_submit_urb) },
	{ 0x78764f4e, __VMLINUX_SYMBOL_STR(pv_irq_ops) },
	{ 0xd3719d59, __VMLINUX_SYMBOL_STR(paravirt_ticketlocks_enabled) },
	{ 0x43261dca, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irq) },
	{ 0xd927ba5b, __VMLINUX_SYMBOL_STR(usb_deregister_dev) },
	{ 0x9d5121d6, __VMLINUX_SYMBOL_STR(_dev_info) },
	{ 0x32e7e0ea, __VMLINUX_SYMBOL_STR(usb_register_dev) },
	{ 0x5a303aa3, __VMLINUX_SYMBOL_STR(usb_alloc_urb) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x9507fe1d, __VMLINUX_SYMBOL_STR(usb_get_dev) },
	{ 0xf432dd3d, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0x190dc627, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0xd3eeff82, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xbd66c37e, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xcf21d241, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0xc3af8d33, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0x71e3cecb, __VMLINUX_SYMBOL_STR(up) },
	{ 0xf2f79e59, __VMLINUX_SYMBOL_STR(usb_free_coherent) },
	{ 0xda3e43d1, __VMLINUX_SYMBOL_STR(_raw_spin_unlock) },
	{ 0xd52bf1ce, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x15b94307, __VMLINUX_SYMBOL_STR(usb_find_interface) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x3707e1ed, __VMLINUX_SYMBOL_STR(usb_put_dev) },
	{ 0x1db9e7d9, __VMLINUX_SYMBOL_STR(usb_free_urb) },
	{ 0xb87e6eb1, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x5a024ea, __VMLINUX_SYMBOL_STR(usb_kill_urb) },
	{ 0xff1076fc, __VMLINUX_SYMBOL_STR(usb_kill_anchored_urbs) },
	{ 0xe6c8b53f, __VMLINUX_SYMBOL_STR(usb_wait_anchor_empty_timeout) },
	{ 0x6e590963, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x784213a6, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:vFFF0pFFF0d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:vFCFCpDEBAd*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "0A055E74AF4B70CF654AA4B");
