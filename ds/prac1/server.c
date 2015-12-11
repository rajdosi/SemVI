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

clientFd = open("cpipe",O_RDONLY);	//open cpipe file
serverFd = open("spipe",O_WRONLY);	//open spipe file

while(1) {
//server-side
printf("File Descriptor for spipe : %d\n", serverFd);
printf("Enter Message : ");
scanf("%s", wrBuffer);
numWrite = write(serverFd, wrBuffer, strlen(wrBuffer));
printf("%d : %s\n", numWrite, wrBuffer);

//client-side
printf("File Descrpitor for cpipe : %d\n", clientFd);
numRead = read(clientFd, buffer, 1023);
printf("%d : %s\n", numRead, buffer);	//print buffer
}

}
