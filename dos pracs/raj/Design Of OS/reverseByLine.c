#include<fcntl.h>
#include<malloc.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	char *ch;
	int by=atoi(argv[3]);
	ch=(char*)malloc(by*sizeof(char));
	int fd1,fd2,rret,wret,temp,l,n,i;
	char tmp;	
	fd1=open(argv[1],O_RDONLY);
	fd2=open(argv[2],O_WRONLY|O_CREAT,0777);
	l=lseek(fd1,-by-1,SEEK_END);
	while(l>=0)
	{
		if(l==0)
			n=read(fd1,ch,temp);			
		else
			n=read(fd1,ch,by);
		for(i=0;i<n/2;i++)
		{
			tmp=ch[i];
			ch[i]=ch[n-i-1];
			ch[n-i-1]=tmp;
		}
		write(fd2,ch,n);
		temp=l;
		if(l==0)
			break;
		else if(l<by)
			l=lseek(fd1,0,SEEK_SET);
		else
			l=lseek(fd1,l-by,SEEK_SET);
	}
	close(fd1);
	close(fd2);

	return 0;

}
