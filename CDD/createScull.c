#include "headers.h"
#include "declaration.h"

Qset* createScull(Dev* ldev, size_t size)
{
	int noi, count, noq;
	Qset* temp;

	printk(KERN_INFO"%s End\n",__func__);
        
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
#ifdef DEBUG
			printk(KERN_INFO"ldev->first:%p\n",ldev->first);
#endif
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
		temp->data=(void**)kmalloc(sizeof(char*)*NOOFREG,GFP_KERNEL);
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

	for(int i=count=0; i<noq;i++, count++)
	{
		*(temp->data)=(char*)kmalloc(sizeof(char)*REGSIZE,GFP_KERNEL);
                if(!*(temp->data))
                {
                        printk(KERN_ERR"Reg size of data\n");
                        goto OUT;
                }
		if(count>7)
		{
			temp=temp->next;
			count=0;
		}


	}
	



	printk(KERN_INFO"%s End\n",__func__);
OUT:
	return (void*)ldev->first;
	
}
