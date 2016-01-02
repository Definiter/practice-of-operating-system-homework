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
	{ 0xb6726ab9, __VMLINUX_SYMBOL_STR(device_remove_file) },
	{ 0xbd66c37e, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xda3e43d1, __VMLINUX_SYMBOL_STR(_raw_spin_unlock) },
	{ 0x458dba77, __VMLINUX_SYMBOL_STR(usb_add_hcd) },
	{ 0x84f3bf6d, __VMLINUX_SYMBOL_STR(usb_remove_hcd) },
	{ 0x1cb3b5d8, __VMLINUX_SYMBOL_STR(usb_create_hcd) },
	{ 0x7cf63481, __VMLINUX_SYMBOL_STR(usb_hcd_poll_rh_status) },
	{ 0x19c6b7f8, __VMLINUX_SYMBOL_STR(driver_for_each_device) },
	{ 0x6e590963, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0xe603d05c, __VMLINUX_SYMBOL_STR(usb_hcd_giveback_urb) },
	{ 0x4629334c, __VMLINUX_SYMBOL_STR(__preempt_count) },
	{ 0x256e5e9c, __VMLINUX_SYMBOL_STR(__platform_driver_register) },
	{ 0xc37619ba, __VMLINUX_SYMBOL_STR(usb_put_hcd) },
	{ 0xfb578fc5, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x353c61b5, __VMLINUX_SYMBOL_STR(usb_hcd_link_urb_to_ep) },
	{ 0xc3af8d33, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0x8f64aa4, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xd8b6e92d, __VMLINUX_SYMBOL_STR(platform_device_alloc) },
	{ 0x4224b193, __VMLINUX_SYMBOL_STR(platform_device_add) },
	{ 0xb87e6eb1, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x2ad6e74, __VMLINUX_SYMBOL_STR(platform_device_unregister) },
	{ 0xf45107c3, __VMLINUX_SYMBOL_STR(device_create_file) },
	{ 0xf677f358, __VMLINUX_SYMBOL_STR(usb_hcd_check_unlink_urb) },
	{ 0xf4b058c3, __VMLINUX_SYMBOL_STR(module_put) },
	{ 0x9d5121d6, __VMLINUX_SYMBOL_STR(_dev_info) },
	{ 0x9507fe1d, __VMLINUX_SYMBOL_STR(usb_get_dev) },
	{ 0xc081828c, __VMLINUX_SYMBOL_STR(driver_create_file) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x3707e1ed, __VMLINUX_SYMBOL_STR(usb_put_dev) },
	{ 0xe5189a6a, __VMLINUX_SYMBOL_STR(platform_device_add_data) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0xd3eeff82, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xd52bf1ce, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xae44f6e8, __VMLINUX_SYMBOL_STR(__dynamic_dev_dbg) },
	{ 0x9327f5ce, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0x19a304ba, __VMLINUX_SYMBOL_STR(usb_disabled) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x37534376, __VMLINUX_SYMBOL_STR(dev_warn) },
	{ 0xbad15b19, __VMLINUX_SYMBOL_STR(driver_remove_file) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x68815f51, __VMLINUX_SYMBOL_STR(platform_driver_unregister) },
	{ 0xf47c2bb6, __VMLINUX_SYMBOL_STR(usb_hcd_unlink_urb_from_ep) },
	{ 0x9479ed9c, __VMLINUX_SYMBOL_STR(try_module_get) },
	{ 0x9662585a, __VMLINUX_SYMBOL_STR(platform_device_put) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "9E700B46FBDA1647A9A2865");
