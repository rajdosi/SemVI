#include<iostream>
#include<stdio.h>


using namespace std;

int main()
{
    int add_size,blk_size,no_blk,no_addr,off,no_blk1,no_blk2,no_blk3;
    long int offset;
    cout<<"\n enter the block size:";
    cin>>blk_size;
    cout<<"\n enter the address size:";
    cin>>add_size;
    no_addr=blk_size/add_size;
    cout<<"\n the no. of addresses which can be accomodated in one block are:"<<no_addr;
    cout<<"\n enter the offset for which the block no. should be found:";
    cin>>offset;
    no_blk=offset/blk_size;
    cout<<"\n the no. of blocks required are:"<<no_blk;
    off=offset%blk_size;
    if(no_blk>9)
    {
     	no_blk=no_blk-10;
     	if(no_blk>no_addr)
     	{
     		no_blk=no_blk-no_addr;
     		if(no_blk>no_addr)
     		{
     			no_blk=no_blk-no_addr*no_addr;
     		}
     		else
     		{
     			
     			cout<<"\n the offset lies double indirect block:"<<
     		}
     	}
     	else
     	{
     		cout<<"\n the offset lies in single indirect block no:"<<no_blk<<" at offset:"<<off;
     	}
    }
    else
    {
    	cout<<"\n the offset lies in direct block no.:"<<no_blk<<" at offset:"<<off;
    }

    return 1;
}
