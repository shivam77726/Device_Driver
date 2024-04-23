#include "headers.h"
#include "declaration.h"

void* releaseDevice(void* arg)
{
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif

	close(fd);

#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif
	return (void*)0;
}
