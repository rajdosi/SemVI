#include<iostream>
#include<bits/stdc++.h>

#define number_block 4
#define free_list  5


using namespace std;

int number_inode;
struct cache
{
	int inode_number;
	int reference;
	int link;
	char state;
	struct cache *next;
	struct cache *next_free;
}*cache_block[number_block],*free_linked_list;

void initialize()
{
	for (int i=0;i<number_block;i++)
	{
		cache_block[i]= NULL;
	}
	free_linked_list=NULL;
}

void free_inode()
{
}

void add_to_free()
{
}

void update_inode()
{
}

void free_datablock()
{
}

void show(int k)
{
	struct cache *temp;
	cout<<endl;
	for(int i=0;i<number_block;i++)
	{
		temp = new cache;
		if(cache_block[i]==NULL)
		{
			cout<<"This hash queue is empty."<<endl;
		}
		else
		{
			temp = cache_block[i];
			while(temp->next!=NULL)
			{
				cout<<temp->inode_number<<"("<<temp->reference<<")("<<temp->state<<")-->";
				temp=temp->next;
			}
			cout<<temp->inode_number<<"("<<temp->reference<<")("<<temp->state<<")-->"<<endl;
		}
	}
}

void show_free()
{
		if(free_linked_list==NULL)
		{
			cout<<"empty."<<endl;
			return;
		}
		struct cache *temp;
		cout<<endl;	
			temp = free_linked_list;
			while(temp->next_free!=NULL)
			{
				cout<<temp->inode_number<<"("<<temp->reference<<")-->";
				temp=temp->next_free;
			}
			cout<<temp->inode_number<<"("<<temp->reference<<")-->"<<endl;
}

int main()
{
	int i_node,queue_number,choice;
	bool temp_state;
	//cout<<"Enter number of blocks."<<endl;
	//cin>>number_block;

	//cout<<"Enter number of i-nodes in one hash queue."<<endl;
	//cin>>number_inode;

	number_inode=free_list;
	struct cache *freelist;
	struct cache *temp;
	struct cache *temp_next;
	struct cache *temporary;
	struct cache *previous;

	initialize();

	while(5)
	{
		cout<<endl<<endl;
		cout<<"1. To Enter i-node number."<<endl;
		cout<<"2. To Lock i-node."<<endl;
		cout<<"3. To Unlock i-node."<<endl;
		cout<<"4. To Close file."<<endl;
		cin>>choice;
		cout<<endl<<"Enter I-node numbner for given purpose."<<endl;
		cin>>i_node;
		queue_number=i_node % number_block;

		switch(choice)
		{
			case 1 :{
			
				if(cache_block[queue_number]!=NULL)
				{
					temporary = new cache;	
					temporary=cache_block[queue_number];
					while(temporary->inode_number!= i_node && temporary->next!=NULL)
					{
						temporary=temporary->next;
					}
					if(temporary->inode_number==i_node && temporary->state =='U')
					{
						if(temporary->reference==0)
						{
							temp = new cache;
							previous = new cache;
							temp = free_linked_list;
							while(temp->next_free!=NULL && temp->inode_number!=i_node)
							{
								previous=temp;
								temp=temp->next_free;
							}	
							if(temp->next_free==NULL)
								previous->next_free=NULL;
							else
								{							
									previous->next_free=temp->next_free;
									temp->next_free=NULL;
								}
						}
						temporary->reference=temporary->reference+1;
						show(queue_number);
						show_free();
						continue;
					}
					if(temporary->state =='L')
					{
						cout<<endl<<"I-node is locked. You have to wait."<<endl;
						continue;
					}
				}
				if(number_inode)
				{
					if(cache_block[queue_number]==NULL)
					{
						temp_next = new cache;
						cache_block[queue_number]= temp_next;
					}
					else
					{
						temp = new cache;
						temp=cache_block[queue_number];
						while(temp->next!=NULL)
						{
							temp=temp->next;
						}
						temp_next = new cache;
						temp->next = temp_next;
					}
					temp_next->next=NULL;
					temp_next->next_free=NULL;
					temp_next->inode_number=i_node;
					temp_next->reference=1;
					temp_next->state='U';
					number_inode--;
					show(queue_number);
					show_free();
				}
				else
				{
					cout<<"Free List Is Empty"<<endl;		
				}
				}
				break;
			case 2 :
				{
					if(cache_block[queue_number]!=NULL)
					{
						temporary = new cache;	
						temporary=cache_block[queue_number];
						while(temporary->inode_number!= i_node && temporary->next!=NULL)
						{
							temporary=temporary->next;
						}
						if(temporary->inode_number==i_node)
						{
							if(temporary->state=='L')
							{
								cout<<"I-node is already locked."<<endl;
								continue;	
							}
							temporary->state='L';
							show(queue_number);
							show_free();
							continue;
						}
						
					}
					cout<<"I-node is not in Hash Queue."<<endl;
				}
				break;
			case 3 :
				{
					if(cache_block[queue_number]!=NULL)
					{
						temporary = new cache;	
						temporary=cache_block[queue_number];
						while(temporary->inode_number!= i_node && temporary->next!=NULL)
						{
							temporary=temporary->next;
						}
						if(temporary->inode_number==i_node)
						{
							if(temporary->state=='U')
							{
								cout<<"I-node is not locked."<<endl;
								continue;	
							}
							temporary->state='U';
							show(queue_number);
							show_free();
							continue;
						}
						
					}
					cout<<"I-node is not in Hash Queue."<<endl;
				}
				break;
			case 4 :
				{
					if(cache_block[queue_number]!=NULL)
					{
						temporary = new cache;	
						temporary=cache_block[queue_number];
						while(temporary->inode_number!= i_node && temporary->next!=NULL)
						{
							temporary=temporary->next;
						}
						if(temporary->inode_number==i_node)
						{
							if(temporary->state=='L')
							{
								cout<<"I-node is already locked."<<endl;
								continue;	
							}
							else
							{
								temporary->state='L';
								temporary->reference-=1;
								if(temporary->reference==0)
								{
									if(temporary->link==0)
									{
										free_datablock();
										free_inode();
									}
									update_inode();
									add_to_free();
									number_inode++;
									if(free_linked_list==NULL)
									{
										free_linked_list = temporary;	
									}
									else
									{
										temp = new cache;
										temp = free_linked_list;
										while(temp->next_free!=NULL)
										{
											temp=temp->next_free;
										}
										temp->next_free = temporary;
									}
								}
								temporary->state='U';	
							}
						show(queue_number);
						show_free();
						continue;
						}
						
					}
					cout<<"I-node is not in Hash Queue."<<endl;
				}
				break;
		}
	}
}


















	


