#include "headers.h"
#include "declaration.h"
static void __exit cleanup(void)
{
	printk(KERN_INFO "Bye Kernel %s Begin\n",__func__);
	for(int i=0;i<nod;i++)
		cdev_del(&myDev[i].mycdev);
	kfree(myDev);
	unregister_chrdev_region(DevId,nod);

	printk(KERN_INFO "Bye Kernel %s End\n",__func__);
}

module_exit(cleanup);
