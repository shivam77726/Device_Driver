#define NOF 7
void* exitApps(void*);
void* mainMenu(void*);
void* openDevice(void*);
void* releaseDevice(void*);
void* writeDevice(void*);
void* readDevice(void*);
void* seekDevice(void*);

void* (*fptr[NOF])(void*);


int init(void)
{
	fptr[0]=mainMenu;
	fptr[1]=exitApps;
	fptr[2]=openDevice;
	fptr[3]=writeDevice;
	fptr[4]=readDevice;
	fptr[5]=releaseDevice;
	fptr[6]=seekDevice;

	return 0;
}
