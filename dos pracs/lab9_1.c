#include<stdio.h>

#include<signal.h>
//#include<sys/wait.h>



void f1();

int main()
{
	int r[50],pid,i;
	signal(SIGINT,f1);
	pid=getppid();
	for(i=0;i<5;i++)
	{
		if(fork()==0)
		{
			if(i%2==0)
			{
				setpgrp();
			}
		}
	}
	kill(0,SIGINT);
	//wait(&r);
	return 0;
}

void f1()
{
	printf("signal recd.");
	
}
