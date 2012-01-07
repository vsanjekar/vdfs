/*
 * linux/fs/vdfs/internal.h
 */


/* 
 * Function declarations 
 * */

/*
 * super.c
 */
int __init register_vdfs(void);
struct inode *vdfs_alloc_inode(void);
void vdfs_destroy_inode(struct inode *inode);
int vdfs_write_inode(void);

