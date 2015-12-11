//reversing a file character by character


//include<sys/types.h>

using namespace std;

int main(int argc,char *argv[])
{
	int f1,f2,offset=0,count,rd,i;
	char buffer[1024];
	if(argc!=3)
	{
		perror("\nInvalid no. of arguments:");
	}
	else
	{
		f1=open(argv[1],O_RDONLY);		
		f2=open(argv[2],O_RDWR | O_CREAT,0666);
		
		if(f1==-1)
		{
			cout<<"\n the file from which you wish to reverse doesn't exists:";
		}
		else
		{
			count=lseek(f1,offset,SEEK_END);
			
			
			offset=count;
			
			while(offset>=0)
			{
								
				rd=read(f1,buffer,1);
				write(f2,buffer,1);
				offset=offset-1;
				lseek(f1,offset,SEEK_SET);
			}
			cout<<"\n read the reversed file :";
 
		}
	}
	close(f1);
	close(f2);
	return 0;
	
}
