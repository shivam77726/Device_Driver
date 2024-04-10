#include "headers.h"
#include "declaration.h"

void* exitApps(void* arg)
{
	int *flag;
	flag=(int*)arg;
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
	if(flag)
	{
		
		if(*flag==0)
			printf("Success\n");
		else
			printf("Failure: exit code %d\n",*flag);


#ifdef DEBUG
		printf("%s End.\n",__func__);
#endif
		exit(*flag);
	}
	printf("Argument passed to exit function is NULL pointer\n");
#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif
	exit(0);
	return (void*)0;
}
