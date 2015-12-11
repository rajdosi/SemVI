#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
	mkfifo("pipe1", 0666);
	mkfifo("pipe2", 0666);
	int fd1, fd2;
	fd1=open("pipe1", O_RDWR);
	fd2=open("pipe2", O_RDWR);
	char s[1024];
	char buf[100];
	
	int pid= fork();
	
	if(pid==0)
	{
		while(1)
		{
			read(fd1, buf, 100);
			cout<<"CHILD [Message Received]: "<<buf<<endl<<endl;
			cout<<"CHILD [Enter Message]: ";
			gets(s);
			write(fd2, s, 100);
		}
	}
	else
	{
		while(1)
		{
			cout<<"PARENT [Enter Message]: ";
			gets(s);
			write(fd1, s, 100);
			read(fd2, buf, 100);
			cout<<"PARENT [Message Received]:"<<buf<<endl<<endl;
			
		
		}
	}
	return 0;
}
