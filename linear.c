#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int l=0,m=0;

void insert(int x,int k,int ll[])
{
	if(k<0 || k>l || l==m)
	printf("Data cannot be inserted! list is full.\n");
	else
	{
	for(int i=l-1;i>=k;i--)
	{
		ll[i+1]=ll[i];	
	}
	ll[k]=x;
	}
	printf("Elements inserted!\n");	
}

bool find(int a[],int loc,int *x)
{
	if(loc<0 || loc>l-1)
		return false;
	else
	{
		*x=a[loc];
		return true;
	}
	return false;
}

bool search(int a[],int x)
{
	for(int i=0;i<l;i++)
	{
		if(a[i]==x)
			return true;
	}
	return false;
}

void delete(int a[],int loc)
{
	if(loc<0 || loc>l)
		printf("Wrong indexing! Try again.\n");
	else
	{
		for(int i=loc;i<l;i++)
			a[i-1]=a[i];
		l--;
	}
	printf("Element deleted.\n");
}

int main()
{
	int *ll=NULL;
	int ch=l=m=0,x,loc;
	bool r;
	while(ch != -1)
	{
		switch(ch){
			case 0:
			printf("Enter 1 to create ll\n");
			printf("Enter 2 to destroy ll\n");
			printf("Enter 3 to check if its empty.\n");	
			printf("Enter 4 to find the length.\n");
			printf("Enter 5 to find the element at kth location and store it.\n");
			printf("Enter 6 to search the element in ll.\n");
			printf("Enter 7 to delete element at kth location.\n");
			printf("Enter 8 to insert element at kth location.\n");
			printf("Enter 9 to show output\n");
			printf("Enter 0 to show menu\n");
			break;

			case 1:
			printf("Enter max size of ll.");
			scanf("%d",&m);
			ll=(int *)malloc(sizeof(int)*m);
			printf("Enter no of elements to insert.\n");
			int y;scanf("%d",&y);
			printf("Enter elements one by one.\n");
			for(int i=0;i<y;i++)
			{
				int temp;scanf("%d",&temp);
				insert(temp,i,ll);
				l++;
			}		
			break;

			case 2:
			free(ll);
			ll=NULL;
			printf("linear list destroyed.\n :-(\n");
			l=0;m=0;
			break;		
			
			case 3:
			if(l<=0) printf("Linear list is empty.\n");
			else printf("Linaer list is not empty.\n");
			break;

			case 4:
			printf("Size of the ll is %d .\n",l);
			break;

			case 5:
			printf("Enter the loaction where the elements to be searched?\n");
			scanf("%d",&loc);
			;
			r=find(ll,loc-1,&x);
			if(r==true)
				printf("Element at %dth location is %d .\n",loc,x);
			else
				printf("Something went wrong! Check your input and try again.\n");
			break;

			case 6:
			printf("Enter element to be searched in ll.\n");
			scanf("%d",&x);
			r=search(ll,x);
			if(r==true)
				printf("Element found !\n");
			else
				printf("Element not found!\n");
			break;

			case 7:
			printf("Enter loaction at which you want to delete.\n");
			scanf("%d",&loc);
			delete(ll,loc);
			break;

			case 8:
			printf("Enter the data to be entered alongwith location at which the element to be entered.\n");
			scanf("%d %d",&x,&loc);
			insert(x,loc-1,ll);
			l++;
			break;

			case 9:
			if(l<=0)
			printf("Nothing to show.");
			else
			{
			for(int i=0;i<l-1;i++)
			printf("%d -> ",ll[i]);
			printf("%d",ll[l-1]);
			}	
			break;		
		}	
		printf("\nEnter choice\n");
		scanf("%d",&ch);
	}
}