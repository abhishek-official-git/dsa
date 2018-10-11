#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
} node;
int *arr=NULL;
node *addatend(node *start,int data)
{
	node *tmp,*p;
	tmp=(node*)malloc(sizeof(node));
	tmp->data=data;
	p=start;
	while(p->next!=NULL)
		p=p->next;
	p->next=tmp;
	tmp->next=NULL;
	tmp->prev=p;
	return start;
}
node *addtoempty(node *start,int data)
{
	node *tmp;
	tmp=(node*)malloc(sizeof(node));
	tmp->data=data;
	tmp->prev=NULL;
	tmp->next=NULL;
	start=tmp;
	return start;
}
node *create_list(node *start, int n)
{
	int i, data;
	start=NULL;
	for(i=1;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		if(start==NULL)
			start=addtoempty(start,data);
		else
			start=addatend(start,data);	
	}
	return start;
}
void construct(node *in,node *pre,int i,int num)
{
	if(num==0) return; 
	arr[i]=pre->data;
	int j;node*q=in;
	for(j=0;pre->data!=q->data;j++)
	{
		q=q->next;
	}
	construct(in,pre->next,2*i,j);
	for(int k=1;k<=j+1;k++)
	{
		pre=pre->next;
	}
	construct(q->next,pre,2*i+1,num-j-1);
	return;
}
void print(int n)
{
	printf("\n");
	for(int i=1;i<=n;i++)
		printf(" %d ",arr[i]);
}
int main(void)
{
	node *pre=NULL,*in=NULL;
	int num;
	printf("Enter no of nodes!\n");
	scanf("%d",&num);
	arr=(int*)malloc(sizeof(int)*num+1);
	arr[0]=0;
	printf("Enter inorder\n");
	in=create_list(in,num);
	printf("Enter preorder\n");
	pre=create_list(pre,num);
	construct(in,pre,1,num);
	print(num);
}