#define NOF 6

extern int fd;
int init();
extern void* exitApps(void*);
extern void* mainMenu(void*);
extern void* openDevice(void*);
extern void* releaseDevice(void*);
extern void* writeDevice(void*);
extern void* readDevice(void*);

extern void* (*fptr[NOF])(void*);
