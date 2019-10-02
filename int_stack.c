#include<stdio.h>
#include<stdlib.h>
struct Stack{
	double data;
	struct Stack* next;
};

typedef struct Stack stack;

double peep(stack * t)
{
	if(t==NULL)
	{
		//printf("Stack empty!\n");
		return 0;
	}

	else
		return t->data;
}

stack* pop(stack * t)
{
	if(t==NULL)
		return NULL;
	else
	{
		stack *p=t;
		t=t->next;
		free(p);
		return t;
	}
}
stack* push(stack *t,double x)
 {
    //cretes a new node, adds the data in it and return it
 	stack* temp=(stack*)malloc(sizeof(stack));
 	temp->data=x;
 	temp->next=t;
 	return temp;
 }
