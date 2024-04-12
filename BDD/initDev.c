#include "headers.h"
#include "declaration.h"

int majorno;

static int __init initDev(void)
{
	printk(KERN_INFO"Hello Kernel %s Begin\n",__func__);



	majorno=register_blkdev(MAJORNO,DevName);
	if(majorno<0)
	{
#ifdef DEBUG
		printk(KERN_ERR"Not Registered\n");
#endif
		goto OUT;
	}

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
