MODULE_LICENSE("GPL");


#ifndef MAJORNO
#define MAJORNO 0
#endif
#ifndef MINORNO
#define MINORNO 0 
#endif
#ifndef DEVSIZE
#define DEVSIZE 128
#endif

#ifndef DATASIZE
#define DATASIZE 0
#endif

#ifndef REGSIZE
#define REGSIZE 4
#endif

#ifndef NOOFREG
#define NOOFREG 8
#endif

#ifndef NOD
#define NOD 1
#endif

extern unsigned int majorNo, minorNo;
extern int devSize, dataSize, regSize, noofReg,nod;
extern dev_t DevId;
extern struct qset *first;
extern struct dev *myDev;

typedef struct qset
{
	struct qset *next;
	void **data;
}Qset;


typedef struct dev
{
	Qset *first;
	int devSize;
	int dataSize;
	int regSize;
	int noofReg;
	struct cdev mycdev;

}Dev;

int openDev(struct inode*, struct file *);
int releaseDev(struct inode*, struct file*);
int trimDev(Dev*);
ssize_t writeDev(struct file*, const char __user*, size_t, loff_t*);
ssize_t readDev(struct file*, char __user*, size_t, loff_t*);

