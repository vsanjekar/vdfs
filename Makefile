obj-m +=super.o
obj-m +=inode.o
obj-m +=vdfs.o
vdfs-objs := super.o inode.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
