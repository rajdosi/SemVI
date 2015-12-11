#include<unistd.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<fcntl.h>
#include<iostream>
using namespace std;

int main(int argc,char *argv[])
{
	int f1,f2,rd,rd1;
	char buffer[1024];
	char str[1024]; 
	if(argc!=3)
	{
		perror("\nInvalid Arguments:");
	}
	else
	{

		f1=open(argv[1],O_CREAT || O_RDWR,0666);
		rd1=read(f1,buffer,sizeof(buffer));
		if(rd1==0)
		{
			cout<<"\n enter the string:";
			cin>>str;
			int l1=strlen(str);
			write(f1,str,l1);
		}		
		
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
	close(f1);
	close(f2);
}
