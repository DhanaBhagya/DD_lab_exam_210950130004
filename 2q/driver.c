#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/uaccess.h>
#include<linux/semaphore.h>
#include<linux/wait.h>
struct file_operations fop
{
	.owner =THIS_MODULE,
	.read =fop_read,
	.write = fop_write,
	.open = fop_open,
	.release = fop_release,
};
struct cdev *my_cdev;


static int __device_init(void)
{
	
	
	int dev1;
	dev1 = alloc_chrdev_region(dev1,0,2,mydev);
	cdev_init(cdev,fops);
	
}
static void  __device_exit(void)
{
	unregister_chrdev_region(dev1,2);
	cdev_del(dev1);

}
module_init(device_init);
module_exit(device_exit);
