#include<stdio.h>
#include<stdlib.h>
struct Stack{
	char data;
	struct Stack* next;
};

typedef struct Stack stack;

char peep(stack * t)
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
 stack* push(stack *t,char x)
 {
 	stack* temp=(stack*)malloc(sizeof(stack));
 	temp->data=x;
 	temp->next=t;
 	return temp;
 }