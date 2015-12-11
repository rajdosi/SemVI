#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

pid_t createprocess(int numproc) {
	int i;
	pid_t process;
	for (i=0;i<numproc;i++) {
		process = fork();
		if (process == 0)
			return ++i;
	}
	return 0;
}

void joinprocess(pid_t pid) {
	int status;
	pid_t p;
	if (pid != 0)
		exit(0);
	else
		p = wait(&status);
}

int main() {
key_t key = 2434;
size_t size = 1024;
int shmflag, numbers[100], i, n = 100, shmid, intermsum;
pid_t processid;
int *shmptr, *shmp;

for (i=0;i<n;i++) {
	numbers[i] = i;
}

shmid = shmget(key, size, IPC_CREAT | 0755);

shmptr = (int *)shmat(shmid, NULL, 0);
shmp = shmptr;

*shmp = 0;

processid = createprocess(4);
intermsum = *shmptr;
printf("%d", intermsum);
for (i=(processid*20); i<((processid+1)*20); i++) {
	intermsum += numbers[i];
}
*shmptr = intermsum;


joinprocess(processid);
joinprocess(processid);
joinprocess(processid);
joinprocess(processid);

printf("\nExiting\n");
exit(0);
return 0;
}
