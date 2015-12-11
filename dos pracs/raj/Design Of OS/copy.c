#include<fcntl.h> 
#include <errno.h>
#include<stdio.h>
#include<malloc.h>
main(int argc, char** argv) {
	int source,destination,sz,temp;
	char *c;

	source = open(argv[1], O_RDONLY);
	if (source ==-1) {
		fprintf (stderr, "Error Number %d\n", errno);
		perror("Program");
		printf("Fail");
	}

	destination = open(argv[2], O_WRONLY|O_CREAT|O_APPEND,0777);
	c = (char *) malloc(100 * sizeof(char));
	sz = read(source, c, 10);
	while(sz>0)
	{
		write(destination,c,10);
		sz = read(source, c, 10);
	}
	close(source);
	close(destination);
}	

