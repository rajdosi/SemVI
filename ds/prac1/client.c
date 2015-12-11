#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

void main() {

int clientFd, serverFd;	//filefds
ssize_t numRead;	//count read
ssize_t numWrite;	//count write
char buffer[1024];	//buffer
char wrBuffer[1024];

clientFd = open("cpipe",O_WRONLY);	//open cpipe file
serverFd = open("spipe",O_RDONLY);	//open spipe file

while(1) {
//server-side
printf("File Descriptor for spipe : %d\n", serverFd);
numRead = read(serverFd, buffer, 1023);
printf("%d : %s\n", numRead, buffer);

//client-side
printf("File Descriptor for cpipe : %d\n", clientFd);
printf("Enter Message : ");
scanf("%s", wrBuffer);
numWrite = write(clientFd, wrBuffer, strlen(wrBuffer));
printf("%d : %s\n", numWrite, wrBuffer);
}

}
