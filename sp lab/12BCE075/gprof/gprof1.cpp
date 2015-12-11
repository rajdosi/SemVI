#include<iostream>
#include<time.h>
#include<fstream>
#include<stdlib.h>
using namespace std;

void bubble(int *arr,int n)
{
     clock_t a,b;
     int i=0,j=0,temp=0;
     long long int cnt=0;
    a=clock();
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                cnt++;
            }

        }

    }
    b=clock();
    cout<<"bubble sort:-"<<double(b-a)/CLOCKS_PER_SEC<<"    "<<cnt<<endl;

}

void selection(int *arr2,int n)
{
    clock_t a,b;
     int i=0,j=0,temp=0,mini=0,mindex=0;
     long long int cnt2=0;
    a=clock();
    for(i=0;i<n-1;i++)
    { mindex=i;
        for(j=i+1;j<n;j++)
        {
            if(arr2[j]<arr2[mindex])
            {
                mindex=j;

            }

        }
        temp=arr2[i];
        arr2[i]=arr2[mindex];
        arr2[mindex]=temp;
        cnt2++;

    }
    b=clock();

    cout<<"selection sort:-"<<double(b-a)/CLOCKS_PER_SEC<<"    "<<cnt2<<endl;

}

void insertion(int *arr3,int n)
{
    clock_t a,b;
     int i=0,j=0,temp=0,mini=0,mindex=0;
     long long int cnt3=0;
    a=clock();
    for(i=0;i<n-1;i++)
    { j=i+1;
        while(arr3[j]<arr3[j-1] && j>0)
        {
            cnt3++;
            temp=arr3[j];
            arr3[j]=arr3[j-1];
            arr3[j-1]=temp;
            j--;

        }
    }
    b=clock();

    cout<<"insertion sort:-"<<double(b-a)/CLOCKS_PER_SEC<<"    "<<cnt3<<endl;

}

int main()
{
  int n=10000,*arr=new int[n],*arr2=new int[n],*arr3=new int[n],i=0,j=0,temp=0;

    for(i=0;i<n;i++)
    {
         arr[i]=rand()%n;
         arr2[i]=arr[i];
         arr3[i]=arr[i];

    }

    /*for(i=0;i<n;i++)
    {
        arr[i]=i;
        arr2[i]=arr[i];
        arr3[i]=arr[i];
    }*/



    /*cout<<"time of bubble sort is:-"<<bubble(arr)<<endl;
    cout<<"time of selection sort is:-"<<selection(arr2)<<endl;
    cout<<"time of insertion sort is:-"<<insertion(arr3)<<endl;
    */
    bubble(arr,n);
    selection(arr2,n);
    insertion(arr3,n);
    /*for(i=0;i<n;i++)
    {
        cout<<endl<<arr[i];
    }*/
    return 0;
}

