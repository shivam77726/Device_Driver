#include "headers.h"
#include "declaration.h"

int main()
{
	int i=0;
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif
	init();
	while(1)
	{
		fptr[0]((void*)0);		//MainMenu
	}


#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif
	return 0;
}
