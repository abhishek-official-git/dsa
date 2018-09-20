//Polynomial Mutiplication using linked list.
//Author:- Abhishek Kumar
//for more codes go to www.github.com/abhishek-official-git
//7:15 AM 20/09/18
//O(n^3)
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int power;
	int coef;
	struct Node * next;
};
typedef struct Node node;
node* insert(node*a,int c,int p)
{
	node* t=(node*)calloc(1,sizeof(node));
	t->power=p;
	t->coef=c;
	if(a==NULL)
	{
		t->next=NULL;
		return t;
	}
	else if(a->next==NULL)
	{
		if((a->power)<(t->power))
		{
			t->next=a;
			return t;
		}
		else if((a->power)==(t->power))
		{
			a->coef+=c;
			return a;
		}
		else
		{
			a->next=t;
			t->next=NULL;
			return a;
		}
	}
	else
	{
		node*po=a,*q=NULL;
		while(po!=NULL && (po->power)>(p))
		{
			q=po;
			po=po->next;
		}
		if((q->power)==p)
		{
			q->coef+=c;
			return a;
		}
		t->next=q->next;
		q->next=t;
		return a;
	}
}
node * create(void)
{
	node* temp=NULL;
	int opt=0;
	do
	{
		printf("Enter coefffieicet and power!\n");
		int p,c;
		scanf("%d %d",&c,&p);
		temp=insert(temp,c,p);
		printf("\nEnter -1 to exit entering or 1 to continue\n");
		scanf("%d",&opt);
	}while(opt!=-1);
	return temp;
}
node* execute(node* a,node *b)
{
	node *p=a,*q=b;
	node* c=NULL;
	while(p!=NULL)
	{
		while(q!=NULL)
		{
			c=insert(c,(q->coef)*(p->coef),(q->power)+(p->power));
			q=q->next;
		}
		p=p->next;
	}
	return c;
}
void print(node* a)
{
	node* p=a;
	while(p!=NULL)
	{
		if((p->coef)>=0)
		printf("+%dx^%d",p->coef,p->power);
		else
		printf("%dx^%d ",p->coef,p->power);
		p=p->next;
	}
	printf("\n");
}
void main(void)
{
	node * a=NULL,*b=NULL,*c=NULL;
	a=create();
	printf("A==\n");
	print(a);
	b=create();
	printf("B==\n");
	print(b);
	c=execute(a,b);
	printf("C==\n");
	print(c);
}