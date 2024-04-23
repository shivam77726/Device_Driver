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
	ldev=filep->private_data;
	if(!ldev)
	{
		printk(KERN_ERR"%s ERROR:\n",__func__);
		return -1;
	}

	lsize=nob;
	if(nob>= ldev->devSize)
		lsize=ldev->devSize;
	
	item=ldev->first=createScull(ldev,lsize);
	
	i=w=0;
	r=lsize;
	
	if(item==NULL)
	{
		printk(KERN_ERR"Quantum memory not allocated\n");
		return w;
	}

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
			i=0;
		}
		else
			i++;
		dataSize=w;
		r=lsize-w;
	}
	ldev->dataSize=dataSize;

	printk(KERN_INFO"%s End\n",__func__);
	return w;
	
}
