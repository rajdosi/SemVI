#include<stdio.h>
#include<iostream>
#include<signal.h>
#include<sys/wait.h>

using namespace std;

void f1();

int main()
{
	int r[50];
	signal(SIGINT,f1);
	if(fork==0)
	{
		sleep(1);
		int pid=getppid();
		kill(pid,SIGINT);
	}
	wait(&r);
	return 0;
}

void f1()
{
	cout<<"signal recd.";
	
}
