#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/slab.h>
#include<linux/cdev.h>
#include<linux/kernel.h>
#include<linux/uaccess.h>

#include<linux/moduleparam.h>
#include<linux/container_of.h>
#include<linux/semaphore.h>
#include<linux/completion.h>
