#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
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
	{ 0x95c079a4, "module_layout" },
	{ 0x8b6c69c7, "generic_delete_inode" },
	{ 0x6dc850bf, "unregister_filesystem" },
	{ 0xcb1f0407, "register_filesystem" },
	{ 0xc57b2b2d, "d_alloc_root" },
	{ 0x55f66738, "save_mount_options" },
	{ 0xe953b21f, "get_next_ino" },
	{ 0x2769e44, "new_inode" },
	{ 0x34d6f899, "mount_bdev" },
	{ 0x27e1a049, "printk" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "1AE63FC5BCE07C374E6C9AD");
