#include "headers.h"
#include "declaration.h"

void* mainMenu(void* arg)
{
	int choice,ret;
	pthread_t thid;
#ifdef DEBUG
	printf("%s Begin\n",__func__);
#endif

	printf("___MainMenu___\n");
	printf("0.Exit App\n");
	printf("1.Open Device\n");
	printf("2.Write into Device\n");
	printf("3.Read from Device\n");
	printf("4.Release Device\n");
	fflush(stdin);
	printf("Enter Choice:");
	scanf("%d",&choice);
	ret=pthread_create(&thid,0,fptr[choice+1],arg);
	if(ret==-1)
	{
		perror("pthread_create");
		fptr[1]((void*)-1);		//exit apps
	}
	


#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif
	return (void*)0;
}
