#include "headers.h"
#include "declaration.h"

void* seekDevice(void* arg)
{
	int ret,offset;
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
	printf("Enter Offset:");
	scanf("%d",&offset);
	ret=lseek(fd,offset,SEEK_SET);
	if(ret==-1)
	{
		perror("lseek Error");
		fptr[1]((void*)2);
	}
	printf("Pos no:%d\n",ret);


#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif
	return (void*)0;
}
