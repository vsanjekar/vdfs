/*
 * linux/fs/vdfs/inode.c
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#include "internal.h"

/* 
 * Initialize the vdfs
 */
static int __init init_vdfs(void){

	int ret;
	printk("Hi .... Welcome to vdfs!\n");
	ret = register_vdfs();
	return 0;
}

/*
 * Stop vdfs.
 */
static  void __exit exit_vdfs(void){

	printk("Goodbye.\n");
}

MODULE_AUTHOR("Vinay Sanjekar.");
MODULE_LICENSE("GPL");
module_init(init_vdfs);
module_exit(exit_vdfs);
