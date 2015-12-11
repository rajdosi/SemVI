#include<unistd.h>
#include<stdio.h>

#include<fcntl.h>

int main(int argc,char *argv[])
{
	int f1,f2,rd;
	char buffer[1024];

	if(argc!=3)
	{
		perror("\nInvalid Arguments:");
	}
	else
	{

		f1=open(argv[1],O_RDONLY);
	
		if(f1==-1)
		{
			perror("\n OPEN:");
		}
		else
		{	
			f2=open(argv[2],O_WRONLY||O_RDONLY);
			if(f2==-1)
			{
				f2=creat(argv[2],0766);	//	or use f2=open(argv[2],O_RDONLY,0766);
			}
			while(rd=read(f1,buffer,sizeof(buffer)>0))
			{
				write(f2,buffer,rd);
				
			}
		}
	}
	close(f1);
	close(f2);
}
