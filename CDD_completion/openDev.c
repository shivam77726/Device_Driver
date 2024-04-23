#include "headers.h"
#include "declaration.h"

int openDev(struct inode *pnode, struct file *pfile)
{
	Dev *ldev;

	printk(KERN_INFO"%s begin\n",__func__);

	ldev=container_of(pnode->i_cdev,Dev,mycdev);
	if(!ldev)
	{
		printk(KERN_ERR"%s: ERROR: cotainer_of() failure\n",__func__);
		return -1;
	}


	if((pfile->f_flags & O_ACCMODE)==O_WRONLY)
	{
		printk(KERN_INFO"Line Number:%d\n",__LINE__);
		if(down_interruptible(&ldev->sem))
                	return -ERESTARTSYS;
		printk(KERN_INFO"Line Number:%d\n",__LINE__);	
		int ret =trimDev(ldev);
		if(ret==-1)
		{
			printk(KERN_INFO"ERROR:trimDev()\n");
			goto OUT;
		}
		printk(KERN_INFO"File OPening in write mode\n");
		up(&ldev->sem);
	}
	if((pfile->f_flags & O_ACCMODE)==O_RDONLY)
	{
		printk(KERN_INFO"File OPening in read mode\n");
	}
	pfile->private_data=ldev;


	printk(KERN_INFO"%s End\n",__func__);
	return 0;
OUT:
	printk(KERN_INFO"ERROR:return\n");
	return -1;
	
}
