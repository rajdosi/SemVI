#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

int main(int argc,char *argv[])
{
    int f1,f2,offset=0,position,n;
    char buffer[4098],buffer1[4098];
    if(argc != 3)
        perror("\n invalid arguments");
    else
    {
        f1=open(argv[1],O_RDONLY);
        f2=open(argv[2],O_RDWR|O_CREAT,0666);
       
        position=lseek(f1,offset,SEEK_END);
        offset=position;
       
        offset=offset-4096;
        int blocks=0;
        blocks=position/4096;   
        if(position%4096>0)
            blocks++;
        while(blocks>0)
        {
            n=read(f1,buffer,4096);
            for(int i=position-1,j=0;i>=offset;i--,j++)
                buffer1[j%4096]=buffer[i%4096];
            write(f2,buffer1,4096);
            offset=offset-4096;
            lseek(f1,offset,SEEK_SET);

            blocks--;
        }
       
    }
    close(f1);
    close(f2);
return 0;
}
