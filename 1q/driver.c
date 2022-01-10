#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/uaccess.h>

struct stats
{
	int size;
	char buff[];
	int r_w;
};
struct file_operations fops
{
	.owner =THIS_MODULE,
        .read = fops_read,
	.write = fops_write,
	.open = fops_open,
	.release = fops_release,
	.ioctl = fops_iocl,
};

struct cdev *my_cdev;


static int __init device_init(void)
{
	dev_t deviceA;
	int MAJOR;
	int MINOR;
	int reg_deva;
	
	deviceA = MKDEV(9,0);
	MAJOR = MAJOR(deviceA);
	MINOR = MINOR(deviceA);
	reg_deva = register_chrdev_region(deviceA,1,mydevice);
	if(reg_deva == 0)
	{
		printk("\n\n\n allocation of device is success\n\n");
	}
	else
	{
		printk("\n\n\n error occured\n\n");
	}

	struct cdev *my_cdev = cdev_alloc();
	my_cdev->ops=&myfops;
        reg_deva=cdev_add(my_cdev,deviceA,1);
	return 0;
}







static void __exit device_exit(void)
{
	dev_t deviceA;
	int MAJOR;
	int MINOR;
	MAJOR = MAJOR(deviceA);
	MINOR = MINOR(deviceA);
	unregister_chrdev_region(deviceA,1);
	cdev_del(my_cdev);
}

int (open)(struct inode * inode,struct file * filp)
{
	printk("\n\n\nkernel open function\n\n");
	return 0;
}
int (*release)(struct inode * inode,struct file *filp)
{
	printk("\n\n\nkernel close function\n\n");
	return 0;
}

			   

ssize_t read(struct file *filp,char __user*buff,size_t count,loff_t *offp)
{
        
	char kbuff;

	unsigned long buff;
	buff=copy_to_user((char * ubuff),(char * kbuff),count);
	if(buff == 0)
	{
		printk("\n\n indicates end of file\n\n");
	}
	else if(buff<0)
	{
		printk("\n\nerror occurs\n\n");
	}
	else
	{
		printk("\n\ndata transferred\n\n");
	}

}
ssize_t write(struct file *filp,const char __user *buff,size_t count,loff_t *offp)
{
	char kbuff;
	unsigned long buff;
	buff = copy_from_user((char *kbuff),(char *ubuff),count);
	if(buff == 0)
	{
		printk("\n\n indicates end of file\n\n");
	}
	else if(buff>0)
	{
		printk("\n\n\ndata transferred\n\n");
	}
	else
	{
		printk("\n\nerror occurs\n\n")
	}
}
long(*ioctl)(struct file *filp,unsigned int cmd,unsigned long arp)
	switch (cmd)
	case stats :
	        write_read;
		break;

	case default:
	   break;


module_init(device_init);
module_exit(device_exit);







