//Doubly linked lists.
//Author:- Abhishek Kumar
//for more codes go to www.github.com/abhishek-official-git
//8:05 PM 23/09/18
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node
{
	struct Node* prev;
	int data;
	struct Node* next;
};
typedef struct Node node;
int length(node* start);
node* create(node* start);
node* insert(node* start,int data,int i);
bool find(node* start,int pos,int *d);
bool search(node* start,int data,int* pos);
node* delete(node* start,int pos,int *data);
void output(node* start);
int main(void)
{
	node* dll=NULL;
	dll=create(dll);
	printf("length = %d\n",length(dll));
	output(dll);
}
int length(node* start)
{
	if(start==NULL)
		return 0;
	else
	{
		int c=0;
		while(start!=NULL)
		{
			start=start->next;
			c++;
		}
		return c;
	}
}
node* create(node* start)
{
	int n;
	printf("Enter no of elements to be inserted!\n");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		printf("Enter element to be inserted!\n");
		int temp;
		scanf("%d",&temp);
		start=insert(start,temp,i);
	}
	return start;
}
node* insert(node* start,int data,int i)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->prev=NULL;
	temp->next=NULL;
	if(i<1 || i>length(start)+1)
	{
		printf("Cannot Enter Wrong Indexing!");
		return start;
	}
	else if(start==NULL)
	{
		return temp;
	}
	else if(i==1)
	{
		temp->next=start;
		start->prev=temp;
		return temp;
	}
	else
	{
		node* p=start;
		for(int j=1;j<=i-2;j++)
		{
			p=p->next;
		}
		if(i==length(start)+1)
		{
			temp->prev=p;
			p->next=temp;
			return start;
		}
		temp->next=p->next;
		temp->prev=p;
		p->next=temp;
		temp->next->prev=temp;
		return start;
	}
}
bool find(node* start,int pos,int *d)
{
	if(pos<1 || pos>length(start))
		return false;
	else
	{
		for(int i=1;i<pos;i++)
		{
			start=start->next;
		}
		*d=start->data;
		return true;
	}
}
void output(node* start)
{
	int l=length(start);
	for(int i=1;i<l;i++)
	{
		printf("%d <==> ",start->data);
		start=start->next;
	}
	if(start!=NULL)
	{
		printf("%d",start->data);
	}
}
bool search(node* start,int data,int *pos)
{
	int len=length(start);
	for(int i=1;i<=len;i++)
	{
		if(data==start->data)
		{
			*pos=i;
			return true;
		}
		start=start->next;
	}
	return false;
}
node* delete(node* start,int pos,int *data)
{
	if(pos<1 || pos>length(start))
	{
		printf("Nothing to delete\n");
		return start;
	}
	else
	{
		node* p=start;
		for(int i=1;i<=pos-1;i++)
		{
			p=p->next;
		}
		if(pos==length(start))
		{
			p->prev->next=NULL;
			free(p);
			return start;
		}
		else if(pos==1 && length(start)>1)
		{
			p->next->prev=NULL;
			node* q=p->next;
			free(p);
			return q;
		}
		else if(pos==1 && length(start)==1)
		{
			free(p);
			return NULL;
		}
		p->prev->next=p->next;
		p->next->prev=p->prev;
		free(p);
		return start;
	}
}