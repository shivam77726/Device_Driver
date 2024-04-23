#include "headers.h"
#include "declaration.h"
void* readDevice(void* arg)
{
	int ret;
	unsigned char buff[15];
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
	memset(buff,'\0',15);
	ret=read(fd,buff,15);
	if(ret==-1)
	{
		perror("File Open");
		fptr[1]((void*)1);
	}
	printf("%d no of bytes Read Successfully from %s\n",ret,__func__);
	printf("File Read Successfully Messege:%s\n",buff);

#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif
	return (void*)0;
}
