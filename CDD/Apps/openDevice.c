#include "headers.h"
#include "declaration.h"
int fd;
void* openDevice(void* arg)
{
	
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
	char mode[10];
	int i=0;
	printf("Enter Mode(write/read)\n)");
	fflush(stdin);
	/*while(1)
	{
		printf("%s LINE:%d\n",__func__,__LINE__);
		fflush(stdin);
		mode[i++]=getchar();
	//	scanf("%s",mode);
		if(mode[i]=='\n')
			break;
	}
	*/	scanf("%s",mode);
	printf("%s LINE:%d,i:%d\n",__func__,__LINE__,i);
	while(i--)
		printf("%s %c\n",__func__,mode[i]);
	

/*	if(strncmp(mode,"write",5)==0)
	{
		printf("%s LINE:%d\n",__func__,__LINE__);
		fd=open("myDeviceFile",O_WRONLY);
		if(fd==-1)
		{
			perror("File Open");
			fptr[1]((void*)-2);		//exit function
		}
		printf("File Opened Successfully in write mode FD:%d\n",fd);

	}
	else if(strncmp((char*)mode,"read",4)==0)
	{
		printf("%s LINE:%d\n",__func__,__LINE__);
		fd=open("myDeviceFile",O_RDONLY);
		if(fd==-1)
		{
			perror("File Read");
			fptr[1]((void*)-3);		//exit function
		}
		printf("File Opened Successfully in read mode FD:%d\n",fd);

	}

*/


#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif
	return (void*)0;
}
