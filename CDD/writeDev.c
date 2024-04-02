#include "headers.h"
#include "declaration.h"
//#include "fileOper.h"

ssize_t writeDev(struct file *filep, const char __user *ubuff, size_t nob, loff_t *loff )
{
	int noi;
	//int i, noq;
	//size_t lsize;
	Dev* ldev;

	printk(KERN_INFO"%s begin\n",__func__);
	ldev=filep->private_data;

	if(!ldev)
	{
		printk(KERN_ERR"%s ERROR:\n",__func__);
		return -1;
	}

	noi=noofReg*regSize;

	



	printk(KERN_INFO"%s End\n",__func__);
	return 0;
	
}
