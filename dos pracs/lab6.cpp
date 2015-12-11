//finding a file in the file system

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>


using namespace std;
struct dirent *d1,*d3;
int cnt=0;


	
void search(char name[256],char fil[])
{
	DIR *dr1;
	
	
	//strcpy(nam,name);
	dr1=opendir(name);
	//d3=readdir(dr1);
	while((d3=readdir(dr1))!=NULL)
	{
		if((strcmp(d3->d_name,".")==0) || (strcmp(d3->d_name,"..")==0))
		{
			continue;
		}
		if(d3->d_type==DT_REG)
			{
				
					if(strcmp(d3->d_name,fil)==0)
					{
							strcat(name,"/");
							cnt++;
							strcat(name,fil);
							cout<<"\n the path name is:"<<name<<endl;
							//exit(0);
					}
						
			}
			else	
			{
				strcat(name,"/");
				strcat(name,d3->d_name);
				search(name,fil);
			}
			
	}
	
}


int main(int argc,char *argv[])
{
	
	DIR *dr;
	char fil[20]={'\0'};
	char nam[1256];
	strcpy(fil,argv[1]);
	if(argc!=2)
	{
		cout<<"\n invalid number of arguments";
		
	}
	else
	{
		dr=opendir("/home/raghav");
		//d1=readdir(dr);
		strcpy(nam,"/home/raghav");
		while((d1=readdir(dr))!=NULL)
		{
			if((strcmp(d1->d_name,".")==0) || (strcmp(d1->d_name,"..")==0))
			{
				continue;
			}
			
			if(d1->d_type==DT_REG)
			{
				
					if(strcmp(d1->d_name,fil)==0)
					{
							strcat(nam,"/");
							cnt++;
							strcat(nam,fil);
							cout<<"\n the path name is:"<<nam;
							//exit(0);
					}
						
			}
			else
			{
				strcat(nam,"/");
				strcat(nam,d1->d_name);
				search(nam,fil);
			}
			
			
		}
		
		
		
	}
	
	cout<<"\n the total no-> of files with name:"<<argv[1]<<"="<<cnt<<"\n";
	return 0;
}
