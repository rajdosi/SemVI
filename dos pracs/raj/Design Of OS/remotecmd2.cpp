#include<iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#define MAX_BUF 10
using namespace std;
int main()
{
	
	int fd;
	char str[100];
	fd = open("myfifo10", O_RDWR);
   	read(fd, str,100);
   	char *argv[10];
   	for(int i=0;i<10;i++) argv[i]=new char(10);
   	argv[2]='\0';
   	int i=0;
   	while(str[i]!=' '){
   		argv[0][i]=str[i++];
   	}
   	i++;
   	int k=0;
   	while(str[i]!='\0'){
   		argv[1][k]=str[i++];
   		k++;
   	}
   	close(1);
   	dup(fd);
   	execvp(*argv,argv);
	return 0;
}

