#include<fcntl.h> 
#include <errno.h>
#include<stdio.h>
#include<malloc.h>
main(int argc, char** argv) {
	int source,destination,sz,temp;
	long position;
	char *c,ch;

	source = open(argv[1], O_RDONLY);
	if (source ==-1) {
		fprintf (stderr, "Error Number %d\n", errno);
		perror("Program");
		printf("Fail");
	}
	destination = open(argv[2], O_WRONLY|O_CREAT,0777);
	c = (char *) malloc(1 * sizeof(char));
	
	position = lseek(source,-2, SEEK_END);
	printf("%i\n",position);
	while(position>=0)
	{
		sz=read(source,c,1);
		write(destination,c,sz);
		position=lseek(source,-2,SEEK_CUR);
		printf("%i\n",position);
	}
	
	close(source);
	close(destination);
}	
