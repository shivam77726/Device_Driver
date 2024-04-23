#include "headers.h"
#include "declaration.h"

int fd;

void* openDevice(void* arg)
{
	int flag=0;
	
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
	char mode[10];
	int i=0;
	
	memset(mode,'\0',10);
	while((getchar())!='\n');
	printf("Enter Mode(write/read):");
	while((mode[i++]=getchar())!='\n');
	mode[i-1]='\0';

	if(strncmp(mode,"write",5)==0)
	{
		printf("%s LINE:%d\n",__func__,__LINE__);
		fd=open("myDeviceFile",O_WRONLY);
		if(fd==-1)
		{
			perror("File Open");
			flag=-2;
			fptr[1]((void*)&flag);		//exit function
		}
		printf("File Opened Successfully in write mode FD:%d\n",fd);

	}
	else if(strncmp(mode,"read",4)==0)
	{
		printf("%s LINE:%d\n",__func__,__LINE__);
		fd=open("myDeviceFile",O_RDONLY);
		if(fd==-1)
		{
			perror("File Read");
			flag=-3;
			fptr[1]((void*)&flag);		//exit function
		}
		printf("File Opened Successfully in read mode FD:%d\n",fd);

	}
	else
		printf("Please Enter correct mode\n");



#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif
	return (void*)0;
}
