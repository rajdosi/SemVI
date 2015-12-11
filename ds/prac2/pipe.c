#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

void main() {
int pipeFd[2];
pid_t cpid;
char buffer[128];
char buf;

if (pipe(pipeFd) < 0) {
	printf("Error in pipe function\n");
	exit(0);
}
cpid = fork();
if (cpid < 0) {
	printf("Error in fork\n");
	exit(0);
}

if (cpid == 0) {
	close(pipeFd[1]);

	while(read(pipeFd[0],&buf,1) > 0) {
		write(STDOUT_FILENO, &buf, 1);
	}
	printf("\n");
	close(pipeFd[0]);
	exit(0);
}
else {
	close(pipeFd[0]);
	printf("Enter Message : ");
	gets(buffer);
	write(pipeFd[1], buffer, strlen(buffer));
	close(pipeFd[1]);
	exit(0);
}
}
