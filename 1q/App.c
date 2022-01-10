#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/ioctl.h>

int main()
{
	int fd;
	char kbuff[100];
	char ubuff[100];
	ssize_t write;
	ssize_t read;
	int close;
	int io;

	fd = open("/dev/mydev",O_RDWR,0777);
	if(fd<0)
	{
		printk("\n\nerror occurs\n");
	}
	write(fd,ubuff,100);
	read(fd,kbuff,100);
	close(fd);
	io = ioctl(fd,mydev,stats);
	if(io = =0)
	{
		printk("\n\nsuccess\n");
	}
	else
	{
		printk("\n\n error\n\n");
	}

}


