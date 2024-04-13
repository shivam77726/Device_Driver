#include "headers.h"
#include "declaration.h"
//#include "fileOper.h"

ssize_t readDev(struct file *filep, char __user *ubuff, size_t nob, loff_t *loff )
{
	size_t lsize=0;
        Dev* ldev=NULL;
        Qset* item=NULL;
        int i,r,ret,noctr;
	char buff[4];

	printk(KERN_INFO"%s begin\n",__func__);

	ldev=filep->private_data;
        if(!ldev)
        {
                printk(KERN_ERR"%s ERROR:\n",__func__);
                return 0;
        }

	lsize=nob;
	printk(KERN_INFO"Line:%d dataSize:%d \n",__LINE__,dataSize);
        if(nob > ldev->dataSize)
        	lsize=ldev->dataSize;

        i=r=0;
        noctr=lsize;
	item=ldev->first;
        if(item==NULL)
        {
                printk(KERN_ERR"Quantum memory not available\n");
                return 0;
        }
	
        while(noctr)
        {
                if(noctr>=ldev->regSize)
                        noctr=ldev->regSize;
		printk(KERN_INFO"Line:%d dataSize:%d noctr:%d r:%d i:%d\n",__LINE__,dataSize,noctr,r,i);
		
		ret=copy_to_user(ubuff+r, item->data[i], noctr);
		if(ret>0)
		{
			printk(KERN_INFO"%s: Partial Read %d\n",__func__,ret);
		}
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
        ldev->dataSize=dataSize;
	
	printk(KERN_INFO"dataSize:%d \n",ldev->dataSize);
	printk(KERN_INFO"%s End\n",__func__);
	return r;
	
}
