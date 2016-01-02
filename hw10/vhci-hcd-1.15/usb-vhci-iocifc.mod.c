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
	{ 0x6bc3fbc0, __VMLINUX_SYMBOL_STR(__unregister_chrdev) },
	{ 0xfcc993ee, __VMLINUX_SYMBOL_STR(class_unregister) },
	{ 0xaef8513e, __VMLINUX_SYMBOL_STR(device_unregister) },
	{ 0xbad15b19, __VMLINUX_SYMBOL_STR(driver_remove_file) },
	{ 0xc081828c, __VMLINUX_SYMBOL_STR(driver_create_file) },
	{ 0x17bfec34, __VMLINUX_SYMBOL_STR(device_register) },
	{ 0xafe5b27a, __VMLINUX_SYMBOL_STR(__class_register) },
	{ 0x68815f51, __VMLINUX_SYMBOL_STR(platform_driver_unregister) },
	{ 0x23b1b022, __VMLINUX_SYMBOL_STR(__register_chrdev) },
	{ 0x256e5e9c, __VMLINUX_SYMBOL_STR(__platform_driver_register) },
	{ 0x19a304ba, __VMLINUX_SYMBOL_STR(usb_disabled) },
	{ 0x1a332b5c, __VMLINUX_SYMBOL_STR(usb_vhci_dev_busnum) },
	{ 0x883ab4be, __VMLINUX_SYMBOL_STR(usb_vhci_dev_name) },
	{ 0xb5c9682c, __VMLINUX_SYMBOL_STR(usb_vhci_dev_id) },
	{ 0xf7a42c3b, __VMLINUX_SYMBOL_STR(usb_vhci_hcd_register) },
	{ 0x9257fec5, __VMLINUX_SYMBOL_STR(usb_vhci_apply_port_stat) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x4f8b5ddb, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x4c4fef19, __VMLINUX_SYMBOL_STR(kernel_stack) },
	{ 0x81107e44, __VMLINUX_SYMBOL_STR(usb_vhci_urb_giveback) },
	{ 0xcee151e5, __VMLINUX_SYMBOL_STR(usb_vhci_maybe_set_status) },
	{ 0xae44f6e8, __VMLINUX_SYMBOL_STR(__dynamic_dev_dbg) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0x26948d96, __VMLINUX_SYMBOL_STR(copy_user_enhanced_fast_string) },
	{ 0xafb8c6ff, __VMLINUX_SYMBOL_STR(copy_user_generic_string) },
	{ 0x72a98fdb, __VMLINUX_SYMBOL_STR(copy_user_generic_unrolled) },
	{ 0xd62c833f, __VMLINUX_SYMBOL_STR(schedule_timeout) },
	{ 0xfa66f77c, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0x34f22f94, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0x8f64aa4, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x9327f5ce, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0x3268082f, __VMLINUX_SYMBOL_STR(usb_vhci_hcd_has_work) },
	{ 0x3bd1b1f6, __VMLINUX_SYMBOL_STR(msecs_to_jiffies) },
	{ 0xf432dd3d, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xcf21d241, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x9479ed9c, __VMLINUX_SYMBOL_STR(try_module_get) },
	{ 0xf4b058c3, __VMLINUX_SYMBOL_STR(module_put) },
	{ 0xf0faa7ec, __VMLINUX_SYMBOL_STR(usb_vhci_hcd_unregister) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=usb-vhci-hcd";


MODULE_INFO(srcversion, "D576598F47609EC9DA1D670");
