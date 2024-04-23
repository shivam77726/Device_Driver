#include "headers.h"
#include "declaration.h"
//#include "fileOper.h"

loff_t lseekDev(struct file *pfile,loff_t offset, int pos)
{
	printk(KERN_INFO"%s begin\n",__func__);
        printk(KERN_INFO"FilePosition:%ld\n",(long)pfile->f_pos);
	pfile->f_pos=offset;

	printk(KERN_INFO"Pos:%ld pos:%d\n",(long)pfile->f_pos, pos);


	printk(KERN_INFO"%s End\n",__func__);
	return pfile->f_pos;
}
