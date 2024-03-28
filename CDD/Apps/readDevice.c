#include "headers.h"
#include "declaration.h"
void* readDevice(void* arg)
{
	int ret;
	char buff[15];
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif

	ret=read(fd,buff,15);
	if(ret==-1)
	{
		perror("File Open");
		fptr[1]((void*)1);
	}
	printf("File Read Successfully Messege:%s\n",buff);

#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif
	return (void*)0;
}
