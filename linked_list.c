#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node * next;
};

typedef struct Node node;

int len(node * start)
{
	if(start==NULL)
		return 0;
	int c=1;
	while(start!=NULL)
	{
		start=start->next;
		c++;
	}
	return c;
}
node * insert(node* start,int loc,int d)
{
	int l=len(start);
	node * p=start;
	node * temp=(node*)malloc(sizeof(node));
	if(loc<1 || loc>l+1)
	{
		printf("Insertion not posible.!\n");
		return start;
	}		
	if(l==0 || loc==1)
	{
		temp->next=start;
		start=temp;
		temp->data=d;
		printf("Insertion completed.\n");
	}
	else
	{
		for(int i=1;i<=loc-2;i++)
		p=p->next;
		temp->next=p->next;
		p->next=temp;
		temp->data=d;
		printf("Insertion completed. \n");
	}	
	return start;
}
void show(node *start)
{
	int l=len(start);
	if(l==0)
	{
		printf("Nothing to print. \n");
	}
	else
	{
		for(int i=1;i<l-1;i++)
		{
			printf(" %d -> ",start->data);
			start=start->next;
		}
		printf(" %d \n",start->data);
	}	
}
node * destroy(node * start)
{
	node * p=start;
	while(start!=NULL)
	{
		start=start->next;
		free(p);
		p=start;
	}
	printf("Destroy of linked list completed! .\n");
	return NULL;
}
node * del(node * start,int loc)
{
	int l=len(start);
	if(loc<1 || loc>l)
	{
		printf("Deletion not possible. \n");
	}
	else
	{
		if(loc==1)
		{
			node *p;
			p=start;
			start=start->next;
			free(p);
		}
		else
		{
			node *p,*q;
			p=start;
			for(int i=1;i<=loc-1;i++)//check this one.
			{
				q=p;
				p=p->next;
			}
			q->next=p->next;
			free(p);
		}		
		printf("Deletion completed!\n");
	}
	return start;
}
node * reverse(node * start)
{
	int l=len(start);
	if(l==0)
	{
		printf("Nothing to reverse! \n");
		return start;
	}
	else
	{
		node *p=start,*q=NULL;
		while(start!=NULL)
		{
			p=start;
			start=start->next;
			p->next=q;
			q=p;
		}
		printf("Reverse complete! \n");
		return q;
	}
}
int main()
{
	node * start=NULL;
	int ch,temp,d;
	ch=temp=d=0;
	while(ch != -1)
	{
		switch(ch)
		{
			case 0:
			printf("Enter 0 to show menu.\n");
			printf("Enter 1 to create linked list.\n");
			printf("Enter 2 to destroy linked list.\n");
			printf("Enter 3 to get the length of likned list.\n");
			printf("Enter 4 to insert element in the linked list.\n");
			printf("Enter 5 to delete element from the linked list.\n");
			printf("Enter 6 to view the linked list.\n");
			printf("Enter 7 to reverse a linked list.\n");
			break;

			case 1:
			printf("Enter the size of link list to begin with.\n");
			scanf("%d",&temp);
			for(int i=1;i<=temp;i++)
			{
				printf("Enter the data to bes inserted to node %d .\n",i);
				scanf("%d",&d);
				start=insert(start,i,d); 
			}
			break;

			case 2:
			start=destroy(start);
			break;

			case 3:
			printf("Size of linked list is: %d \n",len(start));
			break;
 
			case 4:
			printf("Enter the location where you want to insert the data.\n");
			scanf("%d",&temp);
			printf("Enter the data to be intered.\n");
			scanf("%d",&d);
			start=insert(start,temp,d);
			break;

			case 5:
			printf("Enter the node you want to delete. \n");
			scanf("%d",&temp);
			start=del(start,temp);
			break;

			case 6:
			show(start);
			break;

			case 7:
			start=reverse(start);
			break;

			default:
			ch=0;
			break;
		}
		printf("\nEnter your choice? \n");
		scanf("%d",&ch);
	}
	destroy(start);
	
}