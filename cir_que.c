#include<stdio.h>
int front=-1,rear=-1,max=0;
void enque(int *arr,int x);
int deque(int *arr);
int main(void)
{
	int ch=0,m=0;
	do
	{
	printf("Enter maxsize\n");
	scanf("%d",&max);
	}
	while(max<=0);
	int *arr=(int *)malloc(sizeof(int)*max);
	while(ch!=-1){
	switch(ch)
	{
		case 0:
		printf("\nenter 1 to insert element.\n");
		printf("\nenter 2 to delete a emement.\n");
		printf("\nenter 3 to print queue.\n");
		break;
		case 1:
		printf("\nEnter elements to insert!\n");
		int temp;
		scanf("%d",&temp);
		enque(arr,temp);
		break;
		case 2:
		if(front==rear && front==-1){printf("\nNothing to dequeue.\n");break;}
		temp=deque(arr);
		printf("Dequeded element %d.\n",temp);
		break;
		case 3:
		if(front==rear && front==-1)break;
		printf("front->");
		{
		for(int i=front;i!=rear;i=(i+1)%max){
		printf(" %d ",arr[i]);
		}
		printf(" %d <-rear",arr[rear]);
		}
		break;
	}
	printf("\nEnter choice!\n");
	scanf("%d",&ch);
	}//end of while
	free(arr);
}//end of main.
void enque(int *arr,int x)
{
	if((rear+1)%max==front)	printf("\n:-(\nQueue Full\n");
	else
	{
		if(front==rear && rear==-1)
		{
			arr[++rear]=x;
			front=rear;
			printf("\n:-)\n Queded in the order.\n");
		}
		else
		{
			rear=(rear+1)%max;
			arr[rear]=x;
			printf("\n:-)\n Queded in the order.\n");
		}
	}
}
int deque(int *arr)
{
		int t;
		if(front==rear)
		{
			t=arr[front];
			rear=front=-1;
		}
		else
		{
			t=arr[front];
			front=(front+1)%max;
		}
		return t;
}
