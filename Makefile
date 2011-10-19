obj-m +=vdfs_fs.o
obj-m +=super.o
obj-m +=vdfs.o
vdfs-objs := vdfs_fs.o super.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
