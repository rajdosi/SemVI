#include<iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#define MAX_BUF 10
using namespace std;
int main(int argc ,char *argv[]){
    int fd;
    mkfifo("myfifo10", 0666);
	char str[100]={0};
	strcat(str, argv[1]);
	strcat(str," ");
	strcat(str,argv[2]);
	strcat(str,"\0");
	cout << str<<endl;
	 fd = open("myfifo10", O_RDWR);
   	 write(fd, str, strlen(str)+1);
 	 char buf[1001];
 	 int x=1;
 	 x=read(fd,buf,100);
 	 while(x>0){
 	 x=read(fd,buf,100);	  	
 	 cout<<buf;
 	 }
   	 close(fd);
	
return 0;
}

