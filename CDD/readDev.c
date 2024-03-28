#include "headers.h"
#include "declaration.h"
//#include "fileOper.h"

ssize_t readDev(struct file *filep, char __user *ubuff, size_t nob, loff_t *loff )
{

	printk(KERN_INFO"%s begin\n",__func__);



	printk(KERN_INFO"%s End\n",__func__);
	return 0;
	
}
