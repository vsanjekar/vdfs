/*
 * linux/fs/vdfs/super.c
 *
 * author: Vinay Sanjekar
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>

#define VDFS_MAGIC 0x76646673   /* ASCII vdfs */

static int vdfs_fill_super(struct super_block *, void *, int);
/* get_sb is equivalent to mount filesystem */
static struct dentry* vdfs_mount(struct file_system_type *fs_type, int flags, const char *dev_name, void*data);
/*
static int vdfs_get_sb(struct file_system_type *fs_type, int flags, const char *dev_name, void * data, struct vfsmount *mnt); 
*/
static void vdfs_kill_sb(struct super_block *);

struct inode *vdfs_alloc_inode(struct super_block *sb);

static struct file_system_type vdfs_fs_type = {
	.owner		= THIS_MODULE,
	.name		= "vdfs",
	.mount		= vdfs_mount,
	.kill_sb	= vdfs_kill_sb,
	.fs_flags       = FS_REQUIRES_DEV,
};

static const struct super_operations vdfs_sops = {
        .alloc_inode    = vdfs_alloc_inode,
	.drop_inode     = generic_delete_inode,
        /*
        .write_inode    = vdfs_write_inode,
        .destroy_inode  = vdfs_destroy_inode,
        .put_super      = vdfs_put_super,
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

struct inode *vdfs_alloc_inode(struct super_block *sb){

        struct inode * inode = new_inode(sb);

        if (inode) {
                inode->i_ino = get_next_ino();
                inode->i_sb = sb;
                inode->i_op = &vdfs_inode_operations;
                inode->i_fop = &vdfs_file_operations;
        }

        return inode;
}

/* 
 * Fill the vdfs superblock
 */
static int vdfs_fill_super(struct super_block *sb, void *data, int flags){

	struct inode *inode = NULL;
	struct dentry *root;

	save_mount_options(sb, data);

	sb->s_blocksize_bits = 10;
	sb->s_blocksize = 1024;
	sb->s_type = &vdfs_fs_type;
	sb->s_op = &vdfs_sops;
	sb->s_magic = VDFS_MAGIC;

	inode = vdfs_alloc_inode(sb);
	if (!inode) {
		return (-ENOMEM);
	}
	root = d_alloc_root(inode);
	sb->s_root = root;
	if (!root) {
		return (-ENOMEM);
	}

	printk(KERN_INFO "vdfs_fill_super: successfully allocated sb.\n");
	return 0;
}

/* 
 * get the vdfs superblock.
 */
static struct dentry* vdfs_mount(struct file_system_type *fs_type,
		int flags, const char *dev_name, void *data){

	printk(KERN_INFO "vdfs: Mounting.\n");

	return mount_bdev(fs_type, flags, dev_name, data, vdfs_fill_super);
}

/*
 * Unmount vdfs
 */
static void vdfs_kill_sb(struct super_block *sb){

	printk(KERN_INFO "vdfs: Unmounting.\n");

	// Free the super_block
	// free(sb);
	return ;
}

/* 
 * Initialize the vdfs
 */
static int __init init_vdfs(void){

	int ret;

	printk(KERN_INFO "vdfs: init\n");
	ret = register_filesystem(&vdfs_fs_type);

	return 0;
}

/*
 * Exit vdfs.
 */
static  void __exit exit_vdfs(void){

	unregister_filesystem(&vdfs_fs_type);
	printk(KERN_INFO "vdfs: exit.\n");
}

module_init(init_vdfs);
module_exit(exit_vdfs);
MODULE_AUTHOR("Vinay Sanjekar.");
MODULE_LICENSE("GPL");
