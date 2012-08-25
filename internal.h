/*
 * linux/fs/vdfs/internal.h
 */
#define VDFS_MAGIC 0x76646673   /* ASCII vdfs */

extern const struct inode_operations vdfs_inode_operations;
extern const struct file_operations vdfs_file_operations;

struct inode *vdfs_alloc_inode(struct super_block *sb);
