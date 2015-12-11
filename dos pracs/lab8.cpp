#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
	int fd1,fd2,pid,cnt;
	char rdr[1024]={'\0'};
	char wrt[1024]={'\0'};
	
	mkfifo("f1"
	
	pipe(fd1);
	pipe(fd2);
	
	pid=fork();
	
while(1)
{	
	if(pid==0)
	{
		close(fd2[1]);
		close(fd1[0]);
		cout<<"Child message: "<<endl;
		cin>>wrt;
		write(fd1[1],wrt,10);
		sleep(5);
		cout<<"message received: "<<endl;
        read(fd2[0],rdr,10);
        cout<<"\t \t \t"<<rdr<<endl; 
	}
	
	else
	{
		close(fd1[1]);
		close(fd2[0]);
		sleep(5);
		cout<<"message received : "<<endl;
        read(fd1[0],rdr,10);
        cout<<"\t \t \t"<<rdr<<endl; 
		cout<<"Parent message : "<<endl;
		cin>>wrt;
		write(fd2[1],wrt,10);
		
		
	}

}	
	return 0;
}	
			
			
	
