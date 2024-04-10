#include "headers.h"
#include "declaration.h"

int trimDev(Dev *fdev)
{
	int i;
	Qset *item, *slast;
	printk(KERN_INFO"%s begin\n",__func__);
	
	if(!fdev->first)
	{
		printk(KERN_INFO"Nothing to trim\n");
		return 0;
	}

	while(fdev->first)
	{
		item=slast=fdev->first;
		while(item->next)
		{
			slast=item;
			item=item->next;
		}
		
		if(item->data)
		{
			for(i=fdev->noofReg-1; i>=0;i--)
			{
				if(item->data[i])
				{
					kfree(item->data[i]);
					item->data[i]=NULL;
				}
			}
			kfree(item->data);
			item->data=NULL;
			kfree(item);
			slast->next=NULL;
		}

		if(item==slast)
		{
			fdev->first=NULL;
		}

	}


	printk(KERN_INFO"%s End\n",__func__);
	return 0;
	
}
