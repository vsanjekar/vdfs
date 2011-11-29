#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

#include <linux/fs.h>

struct inode *vdfs_alloc_inode(struct super_block *sb){

	struct inode *inode;

	return inode;

}

void vdfs_destroy_inode(struct inode *inode){

}

int vdfs_write_inode(){

	return 0;
}
