#include "headers.h"
#include "declaration.h"
#include "fileOper.h"

dev_t DevId, devNo;
int devSize, dataSize, regSize, noofReg, nod;
int MajorNo=0,MinorNo=0;
Dev *myDev;

module_param(nod,int,S_IRUGO);

static int __init initDev(void)
{
	int ret;
	printk(KERN_INFO "Hello Kernel %s Begin\tNOD:%d\n",__func__,nod);


	MajorNo=MAJORNO;
	MinorNo=MINORNO;
	//nod=NOD;
	devSize=DEVSIZE;
	dataSize=DATASIZE;
	regSize=REGSIZE;
	noofReg=NOOFREG;

	ret=alloc_chrdev_region(&DevId,MinorNo,nod,"MyDevice1");
	if(ret==-1)
	{
		printk(KERN_ERR"Not Registered\n");
		return -1;
	}
	MajorNo=MAJOR(DevId);
	//MinorNo=MINOR(DevId);

	printk(KERN_INFO "Major NO: %d\n",MajorNo);
	myDev=kmalloc(sizeof(Dev)*nod,GFP_KERNEL);
	if(!myDev)
	{
		printk(KERN_ERR"ERROR: kmalloc() failure\n");
		return -1;
	}

	memset(myDev,'\0',sizeof(Dev)*nod);
	
	for(int i=0; i<nod;i++)
	{
		cdev_init(&myDev[i].mycdev,&fs);

		myDev[i].devSize=devSize;
		myDev[i].dataSize=dataSize;
		myDev[i].regSize=regSize;
		myDev[i].noofReg=noofReg;
		sema_init(&myDev[i].sem,1);
		devNo=MKDEV(MajorNo,i);
				
		ret=cdev_add(&myDev[i].mycdev,devNo,1);
		if(ret==-1)
		{
			printk(KERN_ERR"Error: Cdev_add Failure\n");
			return -1;
		}
		MinorNo=MINOR(myDev[i].mycdev.dev);
		printk(KERN_INFO "Major NO: %d,MinorNo:%d\n",MajorNo,MinorNo);
	}

	printk(KERN_INFO "Hello Kernel %s End\n",__func__);
	return 0;
}

module_init(initDev);
