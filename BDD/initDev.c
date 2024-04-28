#include "headers.h"
#include "declaration.h"

int majorno,nsectors,hardsect_size;

struct Dev* dev;
static int __init initDev(void)
{

	printk(KERN_INFO"Hello Kernel %s Begin\n",__func__);
	
	majorno=MAJORNO;
	nsectors=NSECTORS;
	hardsect_size=HARDSECT_SIZE;


	majorno=register_blkdev(majorno,DEVNAME);
	if(majorno<0)
	{
#ifdef DEBUG
		printk(KERN_ERR"Not Registered\n");
#endif
		goto OUT;
	}
	

        dev=kmalloc(sizeof(struct Dev),GFP_KERNEL);
        if(!dev)
        {
                printk(KERN_ERR"ERROR: kmalloc() failure\n");
                goto OUT;
        }

        memset(dev,'\0',sizeof(struct Dev));
	dev->size=nsectors*hardsect_size;
	dev->data=vmalloc(dev->size);
	if(!dev->data)
	{
		#ifdef DEBUG
		printk(KERN_ERR"vmalloc() failure");
		#endif
		kfree(dev);
		unregister_blkdev(majorno,DEVNAME);
		goto OUT;
	}
	
	spin_lock_init(&dev->spinlock);
	blk_init_queue(bdev_request, &dev->spinlock);


#ifdef DEBUG
	printk(KERN_INFO"Major No:%d\n",majorno);
	printk(KERN_INFO"Hello Kernel %s End\n",__func__);
#endif
	return 0;


OUT:
#ifdef DEBUG
	printk(KERN_ERR"Error %s End\n",__func__);
#endif
	return -1;
}

module_init(initDev);
