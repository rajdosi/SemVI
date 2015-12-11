#include<bits/stdc++.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

using namespace std;
int main()
{
	mkfifo("pipe1", 0666);
	mkfifo("pipe2", 0666);
	int fd1,fd2;
	char str[100];
	cin>>str;
	fd1=open("pipe1", O_WRONLY);
	write(fd1,str,strlen(str)+1);


	char order[100];
	fd2=open("pipe2", O_RDONLY);
	int count=read(fd2,order,20);
	order[strlen(order)]='\0';
	cout<<order;
	close(fd1);
	return 0;
}

