#include<stdio.h>

#include<signal.h>
//#include<sys/wait.h>



void f1();

int main()
{
	int r[50],pid;
	signal(SIGINT,f1);
	if(fork()==0)
	{
		sleep(1);
		pid=getppid();
		kill(pid,SIGINT);
	}
	wait(&r);
	return 0;
}

void f1()
{
	printf("signal recd.");
	
}
