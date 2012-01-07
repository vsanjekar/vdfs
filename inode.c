#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

#include <linux/fs.h>

/* 
 * Function declarations 
 * */
struct inode *vdfs_alloc_inode(struct super_block *sb);
void vdfs_destroy_inode(struct inode *inode);
int vdfs_write_inode(void );


struct inode *vdfs_alloc_inode(struct super_block *sb){

	struct inode *inode = NULL;

	return inode;
}

void vdfs_destroy_inode(struct inode *inode){

	return;
}

int vdfs_write_inode(){

	return 0;
}
