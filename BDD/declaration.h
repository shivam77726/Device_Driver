#ifndef DEBUG
#define DEBUG
#endif

#ifndef DEVNAME 
#define DEVNAME "myBlockDevice"
#endif

#ifndef MAJORNO
#define MAJORNO 0
#endif

#ifndef NSECTORS 
#define NSECTORS 512
#endif

#ifndef HARDSECT_SIZE 
#define HARDSECT_SIZE 1024 
#endif

extern int majorno,nsectors,hardsect_size;

struct Dev
{
	int size;				//Device Size in Sector
	u8 *data;				//The Data Array
	short users;				//How many Users
	//short flag;				//Flag a media change?
	spinlock_t spinlock;			//For mutual exclusion
	struct request_queue *queue;		//The Device request queue
	/*struct gendisk *gd			//The gendisk structure
	struct timer_t timer;			//For simulated media change*/
};

extern struct Dev *dev;
void bdev_request(struct request_queue*);
