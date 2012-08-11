#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include "internal.h"

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

int vdfs_write_inode(void){

	return 0;
}
