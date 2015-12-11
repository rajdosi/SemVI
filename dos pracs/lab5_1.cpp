#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    long int offset;
    int off,bsize,asize,no_addr,no_blk1,no_blk;
    cout<<"\n enter the size of the block:";
    cin>>bsize;
    cout<<"\n enter the size of the address:";
    cin>>asize;
    no_addr=bsize/asize;
    cout<<"\n the no. of addresses which can be accomodated in a block are:"<<no_addr;
    cout<<"\n enter the offset to be searched for:";
    cin>>offset;
    no_blk=offset/bsize;
    off=offset%bsize;
    cout<<"\n so this offset requires:"<<no_blk<<" blocks";
        no_blk1=no_blk;
        no_blk=no_blk-10;
        if(no_blk>0)
        {
            no_blk1=no_blk;           
            no_blk=no_blk-no_addr;
            if(no_blk>0)
            {
                no_blk1=no_blk;               
                no_blk=no_blk-(no_addr*no_addr);
                if(no_blk>0)
                {
                    no_blk1=no_blk;                   
                    no_blk=no_blk-(no_addr*no_addr*no_addr);
                    if(no_blk>0)
                    {
                        cout<<"\n this offset can't be mapped to this architecture.";
                    }
                    else
                    {
                        cout<<"\n this offset lies in triple indirect block at:"<<no_blk1/(no_addr*no_addr)<<" block, pointing to:"<<no_blk1/no_addr<<" block, pointing to:"<<no_blk1%offset<<" at offset:"<<off;
                    }
                }
                else
                {
                    cout<<"\n this offset lies in double indirect block at:"<<no_blk1/no_addr<<" block, pointing to:"<<no_blk1%no_addr<<" block, at offset:"<<off;
                }
            }
            else
            {
                cout<<"\n this offset lies in single indirect block at:"<<no_blk1<<" block, at offset:"<<off;
            }
        }
        else
        {
            cout<<"\n this offset lies in direct block at:"<<no_blk1<<" block at offset:"<<off;
        }
   
    cout<<endl;
    return 0;
}
