/*
 * linux/fs/vdfs/super.c
 *
 * author: Vinay Sanjekar
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>

#include "internal.h"

#define VDFS_MAGIC 0x76646673   /* ASCII vdfs */

/* Function declarations */
static int vdfs_fill_super(struct super_block *, void *, int);
static int vdfs_get_sb(struct file_system_type *fs_type, int flags, 
		const char *dev_name, void * data, struct vfsmount *mnt);
static void vdfs_kill_sb(struct super_block *);

/* Global variables */
struct inode *vdfs_root_inode;

static struct file_system_type vdfs_fs_type = {
	.name		= "vdfs",
	.get_sb		= vdfs_get_sb,
	.kill_sb	= vdfs_kill_sb,
	.owner		= THIS_MODULE,
};

static const struct super_operations vdfs_sops = {
	.alloc_inode	= vdfs_alloc_inode,
	.destroy_inode 	= vdfs_destroy_inode,
	.write_inode	= vdfs_write_inode,
	/*
	.put_super	= vdfs_put_super,
	.statfs         = vdfs_statfs,
	.evict_inode    = vdfs_evict_inode,
	.umount_begin   = vdfs_umount_begin,
	.show_options   = vdfs_show_options,
	.show_stats     = vdfs_show_stats,
	.remount_fs     = vdfs_remount,
	*/
};

const struct inode_operations vdfs_inode_operations = {
	/*
        .permission     = vdfs_permission,
        .getattr        = vdfs_getattr,
        .setattr        = vdfs_setattr,
	*/
};

const struct file_operations vdfs_file_operations = {
	/*
	*/
};

/* 
 * Fill the superblock
 */
static int vdfs_fill_super(struct super_block *sb, void *data, int flags){

	sb->s_blocksize = 1024;
	sb->s_blocksize_bits = 10;
	sb->s_magic = VDFS_MAGIC;
	sb->s_op = &vdfs_sops;
	sb->s_type = &vdfs_fs_type;

	vdfs_root_inode = iget_locked(sb, 1); // Allocate 1st inode
	vdfs_root_inode->i_op = &vdfs_inode_operations; // inode ops
	vdfs_root_inode->i_mode = S_IFDIR | S_IRWXU; 
	vdfs_root_inode->i_fop = &vdfs_file_operations;

	if(!(sb->s_root == d_alloc_root(vdfs_root_inode))){

		iput(vdfs_root_inode);
		return -ENOMEM;
	}

	return 0;
}
/* 
 * Returns the superblock to mount vdfs.
 */
static int vdfs_get_sb(struct file_system_type *fs_type, int flags, 
		const char *dev_name, void * data, struct vfsmount *mnt){

	printk("Hi. Mounting vdfs\n");

	// Get the superblock
	return get_sb_single(fs_type, flags, data, &vdfs_fill_super, mnt);
}

/*
 * Unmount vdfs
 */
static void vdfs_kill_sb(struct super_block *sb){

	// Free the super_block
	printk("Hi. Unmounting vdfs\n");
}

/*
 * Register the vdfs file system
 */
int __init register_vdfs(void){

	int ret;

	if((ret = register_filesystem(&vdfs_fs_type)) != 0){
		// ERROR
		return -1;
	}

	return 0;
}
