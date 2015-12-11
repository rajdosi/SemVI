#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int nproc;
double a[1000];
long int ok,ni=(sizeof(a)/sizeof(double))-1;
long int size=(sizeof(a)/sizeof(double));
double sum=0,status;
pthread_mutex_t lock;
void *work();

int main()
	{

	printf("Enter Number of Threads : ");
	scanf("%d", &nproc);
	pthread_t id;
	pthread_mutex_init(&lock,NULL);
	int i, start;
	printf("[1000 Entries]\nEnter Starting Number : ");
	scanf("%d", &start);
	for (i=start;i<size;i++)
		a[i]=i+1;
//	nproc=atoi(argv[1]);
	ok=0;
	for (i=0;i<nproc;i++)
		{
		if (0==pthread_create(&id,NULL,work,NULL));
			printf("<Thread Created>");
		} 
	
	/*for (i=0;i<100;i++)
		printf("%d\n",a[i]);*/
	while(ni>=0);	
	printf("%f\n",sum/size);
	
	//pthread_exit(&status);
	return 0;
	}
	
void *work()
	{
	int i,ctr;
	ctr=0;
	//while(ok==0);
	do
		{
			pthread_mutex_lock(&lock);
			i=ni--; 
			if (i>=0)
			{
			sum=sum+a[i];
			printf("%f\t%f\n",a[i],sum);
			}
			pthread_mutex_unlock(&lock);
		ctr++;
		}while(i>=0);
	//printf("\nThread %d did %d iterations",pthread_self(),ctr-1);
	ni=-1;
	}
