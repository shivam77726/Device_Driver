#include "headers.h"
#include "declaration.h"

ssize_t writeDev(struct file *filep, const char __user *ubuff, size_t nob, loff_t *loff )
{
	size_t lsize=0;
	Dev* ldev=NULL;
	Qset* item=NULL;
	int i,w,ret,r;
	char buff[4];
	printk(KERN_INFO"%s begin\n",__func__);
	printk(KERN_INFO"FilePosition:%ld\n",(long)filep->f_pos);
	ldev=filep->private_data;
	if(!ldev)
	{
		printk(KERN_ERR"%s ERROR:\n",__func__);
		return -1;
	}
	printk(KERN_INFO"Line Number:%d\n",__LINE__);


	printk(KERN_INFO"Line Number:%d\n",__LINE__);
	lsize=nob;
	if(nob>= ldev->devSize)
		lsize=ldev->devSize;
	//semaphore down
	if(down_interruptible(&ldev->sem))
		return -ERESTARTSYS;	
	item=ldev->first=createScull(ldev,lsize);
	
	i=w=0;
	r=lsize;
	
	if(item==NULL)
	{
		printk(KERN_ERR"Quantum memory not allocated\n");
		up(&ldev->sem);
		return w;
	}

	printk(KERN_INFO"Line Number:%d\n",__LINE__);
	while(w<lsize)
	{
		if(r>=ldev->regSize)
			r=ldev->regSize;
		ret=copy_from_user(item->data[i], ubuff+w, r);
		if(ret>0)
		{
			printk(KERN_INFO"%s: Partial Written\n",__func__);
		}
		w+=r-ret;
		for(int j=0;j<r;j++)
			buff[j]=*(char*)(item->data[i]+j);
		printk(KERN_INFO"ret:%d item->data:%s \n",ret,buff);
	
		if(((i+1)%ldev->noofReg)==0)
		{
			
			item=item->next;
			if(!item)
			{
				printk(KERN_INFO"item next is NULL\n");
				break;
			}	
			i=0;
			if(!item->data[i])
			{
				printk(KERN_INFO"item data is NULL\n");
				break;
			}
		}
		else
			i++;
		dataSize=w;
		r=lsize-w;
	}
	ldev->dataSize=dataSize;
	filep->f_pos=filep->f_pos + w;
	//completion
	complete(&ldev->comp);
	up(&ldev->sem);
	printk(KERN_INFO"FilePosition:%ld\n",(long)filep->f_pos);
	printk(KERN_INFO"%s End\n",__func__);
	return w;
	
}
