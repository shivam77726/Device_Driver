#include "headers.h"
#include "declaration.h"
//#include "fileOper.h"

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
		int ret =trimDev(ldev);
		if(ret==-1)
		{
			printk(KERN_INFO"ERROR:trimDev()\n");
			goto OUT;
		}
	}
	pfile->private_data=ldev;


	printk(KERN_INFO"%s End\n",__func__);
	return 0;
OUT:
	printk(KERN_INFO"ERROR:return\n");
	return -1;
	
}
