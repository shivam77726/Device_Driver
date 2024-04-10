#include "headers.h"
#include "declaration.h"
void* writeDevice(void* arg)
{
	int ret;
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif

	ret=write(fd,"Hello Kernel",13);
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
