#include "headers.h"
#include "declaration.h"

Qset* createScull(Dev* ldev, size_t size)
{
	int noi, count, noq;
	Qset *temp,*temp1;

	printk(KERN_INFO"%s Begin\n",__func__);
        
	noi=size/(ldev->noofReg*ldev->regSize);
        if(size%(ldev->noofReg*ldev->regSize))
                noi++;


	//Allocate space for Struct Qset
        for(int i=0;i<noi;i++)
	{
		temp=(Qset*)kmalloc(sizeof(Qset),GFP_KERNEL);
		if(!temp)
		{
			printk(KERN_ERR"Qset pointer of Qset\n");
			goto OUT;
		}
		memset(temp,'\0',sizeof(Qset));
		temp->next=NULL;
		temp->data=NULL;
		if(!ldev->first)
		{
			ldev->first=temp;
			temp1=ldev->first;
#ifdef DEBUG
			printk(KERN_INFO"ldev->first:%p\n",ldev->first);
#endif
		}
		else
		{
			temp1->next=temp;
			temp1=temp1->next;
		}
		temp=temp->next;
	}
	
#ifdef DEBUG
	printk(KERN_INFO"ldev->first:%p\n",ldev->first);
#endif
	temp=ldev->first;
	
	//Allocate space for Quantum
        for(int i=0;i<noi; i++)
	{
		temp->data=(void**)kmalloc(sizeof(char*)*ldev->noofReg,GFP_KERNEL);
                if(!temp->data)
                {
                        printk(KERN_ERR"Data pointer of Qset\n");
                        goto OUT;
                }
		memset(temp->data,'\0',NOOFREG);
                temp=temp->next;
	}

	temp=ldev->first;

#ifdef DEBUG
	printk(KERN_INFO"ldev->first:%p\n",ldev->first);
#endif

	//Allocate space for Quantums
	noq=size/ldev->regSize;
	if(size%ldev->regSize)
		noq++;

	printk(KERN_INFO"noq:%d\n",noq);
	for(int i=count=0; i<noq;i++)
	{
		printk(KERN_INFO"%d count:%d i:%d\n",__LINE__,count,i);
		temp->data[count]=(char*)kmalloc(sizeof(char)*ldev->regSize,GFP_KERNEL);
                if(!temp->data[count])
                {
                        printk(KERN_ERR"Reg size of data\n");
                        goto OUT;
                }
		memset(*(temp->data),'\0',ldev->regSize);
		count++;	
		if(count>7)
		{
			temp=temp->next;
			count=0;
		}
		printk(KERN_INFO"count:%d,i:%d\n",count,i);

	}
	



	printk(KERN_INFO"%s End\n",__func__);
OUT:
	return (void*)ldev->first;
	
}
