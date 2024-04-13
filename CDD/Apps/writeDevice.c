#include "headers.h"
#include "declaration.h"
void* writeDevice(void* arg)
{
	int ret,len;
	char buff[200]="Hello Kernel";
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
	len=strlen(buff);
	ret=write(fd,buff,len);
	if(ret==-1)
	{
		perror("File write");
		fptr[1]((void*)1);
	}
	printf("File Written Successfully ret:%d\n",ret);

#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif
	return (void*)0;
}
