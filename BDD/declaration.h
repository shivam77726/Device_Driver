#ifndef DEBUG
#define DEBUG
#endif

#ifndef DevName 
#define DevName "myBlockDevice"
#endif

#ifndef MAJORNO
#define MAJORNO 0
#endif



extern int majorno;
extern blkDev *bdev;

typedef struct
{
	int size;				//Device Size in Sector
	u8 *data;				//The Data Array
	short users;				//How many Users
	short flag;				//Flag a media change?
	spinlock_t spinlock;					//For mutual exclusion
	struct requst_t requestqueue;		//The Device request queue
	struct gendisk *gd			//The gendisk structure
	struct timer_t timer;			//For simulated media change
}blkDev;
