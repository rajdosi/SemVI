#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>

int nproc;
double a[1000];
long int ok,ni=(sizeof(a)/sizeof(double))-1;
long int size=(sizeof(a)/sizeof(double));
double sum=0,status, sd=0, ans, avg;
pthread_mutex_t lock;
void *work();
void *sdav();
int main()
	{

	printf("Enter Number of Threads : ");
	scanf("%d", &nproc);
	pthread_t id, sdid;
	pthread_mutex_init(&lock,NULL);
	int i, start;
	printf("[1000 Entries]\nEnter Starting Number : ");
	scanf("%d", &start);
	for (i=start;i<size;i++)
		a[i]=i+1;
	ok=0;
	for (i=0;i<nproc;i++)
		{
		if (0==pthread_create(&id,NULL,work,NULL));
			printf("<Thread Created>");
		} 
	
	while(ni>=0);	
	avg = sum/size;
	printf("%f\n",avg);

	ni=(sizeof(a)/sizeof(double))-1;

	for (i=0;i<nproc;i++)
	{
		if (0==pthread_create(&sdid, NULL, sdav, NULL));
			printf("<Thread Created>");
	}
	while(ni>=0);
	ans = sqrt(sd);
	printf("%f\n", ans/size);
	
	//pthread_exit(&status);
	return 0;
	}
	
void *work()
	{
	int i,ctr;
	ctr=0;
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
	ni=-1;
	}

void *sdav()
	{
		int i, ctr;
		ctr = 0;
		do {
			pthread_mutex_lock(&lock);
			i = ni--;
			if (i>=0)
			{
				sd = sd + (avg - a[i])*(avg - a[i]);
			}
			pthread_mutex_unlock(&lock);
		ctr++;
		} while(i>=0);
		ni = -1;
	}
