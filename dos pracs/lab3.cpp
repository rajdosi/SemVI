//iget ,iput algorithm

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node {
int data;
int ref_cnt;
node *next;
};

int n;

node *head[5];


int search(int inode_no)
{
    node *temp;
    int hash_no = inode_no % 4;
    temp = head[hash_no];

    while(temp != NULL)
        {
        cout << "i-node no : "<<inode_no;
        cout << "temp->data : "<<temp->data;
        cout << endl;
        if(temp->data == inode_no)
            {
            return 1;
            cout << "Hello";
            }
        temp = temp->next;
        }

    return 0;
}

void Insert_end(int x,int hash_no)

{
    if(hash_no == 4)
    {
        node *temp1 = (node*)malloc(sizeof(node));
        temp1 -> data = x;
        temp1 -> next = NULL;
        temp1 -> ref_cnt = 0;

        if(head[hash_no] == NULL){
        temp1 -> next = head[hash_no];
        head[hash_no] = temp1;
        return;
        }

        node *temp2 = head[hash_no];

        while(temp2->next != NULL)
        {
            temp2 = temp2 ->next;
        }
        temp1 -> next = NULL;
        temp2 -> next = temp1;
    }

    else
    {
        if(head[4] == NULL)
        {
            cout << "\nFree list empty. \n";
            return;
        }

        node *temp2 = head[4];                  //temp2 is for traversing the hash queue with number as hash_no
        node *t;
        while(temp2->next != NULL)
        {
            t = temp2;
            temp2 = temp2 ->next;
        }                                       //temp2 will point to last element in the free list


        if(head[hash_no] == NULL){

        head[hash_no] = temp2;
        temp2 -> next = NULL;
        temp2 -> ref_cnt = 1;
        temp2 -> data = x;
        t->next = NULL;

        if(t == head[4])
        {
            head[4] = NULL;
        }
        return;
        }

        node *temp1 = head[hash_no];            //temp1 is for traversing the hash queue with number as hash_no
        if(temp1->data == x)
            {
                temp1->ref_cnt++;
                return;
            }
        while(temp1->next != NULL)
        {
            temp1 = temp1 ->next;
            if(temp1->data == x)
            {
                temp1->ref_cnt++;
                return;
            }
        }                                       //temp1 will point to last element in the list of hash queue

        t->next = NULL;

        if(t == head[4])
        {
            head[4] = NULL;
        }
        temp1 -> next = temp2;
        temp2 -> ref_cnt = 1;
        temp2 -> data = x;
    }

}

void Print()
{
    node *temp;

    cout << "\n";

    for(int i=0;i<5;i++)
    {
    cout << i <<" : ";
    temp = head[i];
    while(temp != NULL)
    {
        if(i != 4)
        {
            cout << temp->data << "(ref:"<<temp->ref_cnt<<") ";
        }
        else
        {
            cout << temp->data << " ";
        }
        temp = temp -> next;
    }
    cout << "\n";
    }
}

void iget(int inode_no)
{
    Insert_end(inode_no, inode_no % 4);
}

void iput(int inode_no)
{
    int hash_no = inode_no % 4;

    node *temp, *temp2;

    temp2 = head[4];
    if(temp2 != NULL)
    {
        while(temp2->next != NULL)
        {
            temp2 = temp2 -> next;
        }                               //temp2 will now point to last element in the free list.
    }
    temp = head[hash_no];
    node *t = head[hash_no];
    while(temp != NULL)
    {
        if(temp->data == inode_no)
        {
            temp->ref_cnt--;

            if(temp->ref_cnt == 0)
            {
                t->next = temp->next;
                temp -> next = NULL;
                temp -> data = 0;

                if(temp2 == NULL)
                {
                temp2 = temp;
                head[4] = temp2;
                }
                else
                {
                temp2 -> next = temp;
                }

                if(temp == head[hash_no])
                {
                    head[hash_no] = head[hash_no]->next;
                }
            }
            return;
        }
        t = temp;
        temp = temp->next;
    }
    cout << "\nThis i-node is not in Hash queue.";

}





int main()
{
int ch,i;

int inode_num;

for(i=0;i<4;i++)
    {
    head[i] = NULL;
    }

cout << "Enter number of inodes available in free list : ";
cin >> n;

for (i = 0; i<n; i++)
{
    Insert_end(0,4);
}

while(1)
{
    cout << "\nEnter your choice";
    cout << "\n1. Execute i-get";
    cout << "\n2. Execute i-put";
    cout << "\n3. Show current status";
    cout << "\n4. Exit";
    cout << "\n";

    cin >> ch;

    switch(ch)
    {
     case 1:
        cout << "\nEnter i-node number : ";
        cin >> inode_num;
        iget(inode_num);

        break;

     case 2:
        cout << "i-put";
        cout << "\nEnter i-node number : ";
        cin >> inode_num;
        iput(inode_num);
        break;

     case 3:
        Print();
        break;

     case 4:
        exit(0);
        break;


     default :
        cout << "Wrong choice! Try again.";
     }

}

return 0;
}
