#include<bits/stdc++.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<iostream>

using namespace std;
int main()
{
	char order[100];
	int fd2=open("pipe1",O_RDONLY);
	int count=read(fd2,order,20);
	close(fd2);



	int fd=open("pipe2",O_RDWR);
	close(1);
	dup(fd);
	system(order);
	write(fd,'\0',sizeof('\0'));
	close(fd);
	return 0;
}
