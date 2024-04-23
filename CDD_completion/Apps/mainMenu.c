#include "headers.h"
#include "declaration.h"

void* mainMenu(void* arg)
{
	char c;
	int choice,ret,flag=1;
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
	printf("5.Seek Device\n");
	printf("Enter Choice:");
	scanf("%d",&choice);

	printf("Choice:%d\n",choice);
	if(choice==0)
		flag=0;
	fptr[choice+1]((void*)&flag);
	/*ret=pthread_create(&thid,0,fptr[choice+1],arg);
	if(ret==-1)
	{
		perror("pthread_create");
		flag=-1;
		fptr[1]((void*)&flag);		//exit apps
	}*/
	
	if(choice>5 || choice <0)
		printf("Enter Valid Choice\n");

#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif
	return (void*)0;
}
