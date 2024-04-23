#include "headers.h"
#include "declaration.h"
//#include "fileOper.h"

ssize_t readDev(struct file *filep, char __user *ubuff, size_t nob, loff_t *loff )
{
	size_t lsize=0;
        Dev* ldev=NULL;
        Qset* item=NULL;
        int i,r,ret,noctr,offset;
	char buff[4];

	printk(KERN_INFO"%s begin\n",__func__);

	//semaphore down
	
	printk(KERN_INFO"FilePosition:%ld\n",(long)filep->f_pos);
	ldev=filep->private_data;
        if(!ldev)
        {
                printk(KERN_ERR"%s ERROR:\n",__func__);
                return 0;
        }
	//if(down_interruptible(&ldev->sem))
	//	return -ERESTARTSYS;
	if(ldev->dataSize==0)
		wait_for_completion(&ldev->comp);

	lsize=nob;
	printk(KERN_INFO"Line:%d dataSize:%d \n",__LINE__,dataSize);
        if(nob > ldev->dataSize)
        	lsize=ldev->dataSize;

	lsize=lsize - filep->f_pos;
        
	i=filep->f_pos/ldev->regSize;
	offset=filep->f_pos%ldev->regSize;
	r=0;
	noctr=ldev->regSize-offset;
	if(down_interruptible(&ldev->sem))
                return -ERESTARTSYS;
	item=ldev->first;
        if(item==NULL)
        {
                printk(KERN_ERR"Quantum memory not available\n");
		up(&ldev->sem);
                return 0;
        }
	//dataSize=dataSize - pfile->f_pos;
        while(noctr)
        {
                if(noctr>=ldev->regSize)
                        noctr=ldev->regSize;
		printk(KERN_INFO"Line:%d dataSize:%d noctr:%d r:%d i:%d\n",__LINE__,dataSize,noctr,r,i);
		
		ret=copy_to_user(ubuff+r, item->data[i]+offset, noctr);
		if(ret>0)
		{
			printk(KERN_INFO"%s: Partial Read %d\n",__func__,ret);
		}
		offset=0;
		r+=noctr-ret;
		for(int j=0;j<noctr;j++)
			buff[j]=*(char*)(item->data[i]+j);
		printk(KERN_INFO"ret:%d item->data:%s \n",ret,buff);
                if(((i+1)%ldev->noofReg)==0)
                {
                        item=item->next;
                        i=0;
                }
                else
                        i++;
                dataSize-=r;

                noctr=lsize-r;
		printk(KERN_INFO"dataSize:%d noctr:%d r:%d i:%d\n",dataSize,noctr,r,i);
        }
        dataSize=ldev->dataSize;
	//up(&ldev->sem);
	printk(KERN_INFO"dataSize:%d \n",ldev->dataSize);
	printk(KERN_INFO"FilePosition:%ld\n",(long)filep->f_pos);
	//up semaphore
	up(&ldev->sem);
	printk(KERN_INFO"%s End\n",__func__);
	return r;
	
}
