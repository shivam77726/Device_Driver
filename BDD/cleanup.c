#include "headers.h"
#include "declaration.h"
static void __exit cleanup(void)
{
	printk(KERN_INFO "Bye Kernel %s Begin\n",__func__);

	vfree(dev->data);
	kfree(dev);	
	unregister_blkdev(majorno,DEVNAME);

	printk(KERN_INFO "Bye Kernel %s End\n",__func__);
}

module_exit(cleanup);
