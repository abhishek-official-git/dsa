#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int *l,*m;
int mi,no;

void insert(int x,int k,int ll[])
{
	if(k<0 || k>l[mi] || l[mi]==m[mi])
	printf("Data cannot be inserted! list is full or is never created.\n");
	else
	{
	for(int i=l[mi]-1;i>=k;i--)
	{
		ll[i+1]=ll[i];	
	}
	ll[k]=x;
	}
	printf("Elements inserted!\n");	
}

bool find(int a[],int loc,int *x)
{
	if(loc<0 || loc>l[mi]-1)
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
	for(int i=0;i<l[mi];i++)
	{
		if(a[i]==x)
			return true;
	}
	return false;
}

void delete(int a[],int loc)
{
	if(loc<0 || loc>l[mi])
		printf("Wrong indexing! Try again.\n");
	else
	{
		for(int i=loc;i<l[mi];i++)
			a[i-1]=a[i];
		l[mi]--;
		printf("Element deleted.\n");
	}
	
}

int * merge(int a[],int b[],int ap,int bp,int cp)
{
	int al,bl;
	al=l[ap];
	bl=l[bp];
	int * asdf=(int*)malloc(sizeof(int)*(al+bl+5));
	for(int i=0;i<al;i++)
		asdf[i]=a[i];
	for(int i=0;i<bl;i++)
		asdf[i+al]=b[i];
	m[cp]=al+bl+5;
	l[cp]=al+bl;
	return asdf;
}

int main()
{
	printf("How many linear list, you want to work on.");
	int temp;
	scanf("%d",&no);
	int *ll[no];
	for(int i=0;i<no;i++)
		ll[i]=NULL;
	l=calloc(no,sizeof(int));
	m=calloc(no,sizeof(int));
	int ch=mi=0,x,loc;
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
			printf("Enter 9 to show output.\n");
			printf("Enter 10 to switch ll.\n");
			printf("Enter 11 to merge.\n");
			printf("Enter 0 to show menu\n");
			break;

			case 1:
			printf("Enter max size of ll.");
			scanf("%d",&m[mi]);
			ll[mi]=(int *)malloc(sizeof(int)*m[mi]);
			printf("Enter no of elements to insert.\n");
			int y;scanf("%d",&y);
			printf("Enter elements one by one.\n");
			for(int i=0;i<y;i++)
			{
				scanf("%d",&temp);
				insert(temp,i,ll[mi]);
				l[mi]++;
			}		
			break;

			case 2:
			free(ll[mi]);
			ll[mi]=NULL;
			printf("linear list destroyed.\n :-(\n");
			l[mi]=0;m[mi]=0;
			break;		
			
			case 3:
			if(l[mi]<=0) printf("Linear list is empty.\n");
			else printf("Linaer list is not empty.\n");
			break;

			case 4:
			printf("Size of the ll is %d .\n",l[mi]);
			break;

			case 5:
			printf("Enter the loaction where the elements to be searched?\n");
			scanf("%d",&loc);
			;
			r=find(ll[mi],loc-1,&x);
			if(r==true)
				printf("Element at %dth location is %d .\n",loc,x);
			else
				printf("Something went wrong! Check your input and try again.\n");
			break;

			case 6:
			printf("Enter element to be searched in ll.\n");
			scanf("%d",&x);
			r=search(ll[mi],x);
			if(r==true)
				printf("Element found !\n");
			else
				printf("Element not found!\n");
			break;

			case 7:
			printf("Enter loaction at which you want to delete.\n");
			scanf("%d",&loc);
			delete(ll[mi],loc);
			break;

			case 8:
			printf("Enter the data to be entered alongwith location at which the element to be entered.\n");
			scanf("%d %d",&x,&loc);
			insert(x,loc-1,ll[mi]);
			l[mi]++;
			break;

			case 9:
			if(l[mi]<=0)
			printf("Nothing to show.");
			else
			{
			for(int i=0;i<l[mi]-1;i++)
			printf("%d -> ",ll[mi][i]);
			printf("%d",ll[mi][l[mi]-1]);
			}	
			break;	

			case 10:
			printf("Which ll you want to access!\n");
			scanf("%d",&x);
			if(x>=1 && x<=no)
			{
				mi=x-1;
			}
			else
				printf("Something went wrong! Try again.\n");
			break;	

			case 11:
			printf("Enter which two ll u want to merge.");
			int a,b,c;
			scanf("%d %d",&a,&b);
			if(a>no || a<1 || b>no ||b<1)
			{
				printf("Something went wrong! Try again.(Possible reason: Wrong indexing chosen.)\n");
				break;
			}
			printf("Enter where you want to store this newly merged ll.\n");
			scanf("%d",&c);
			if(c>no || c<1)
			{
				printf("Something went wrong! Try again.(Possible reason: Wrong indexing chosen.)\n");
				break;
			}
			ll[c-1]=merge(ll[a-1],ll[b-1],a-1,b-1,c-1);
			printf("Merge completed! Now you can select newly merged ll using option 10. \n");
			break;

			default:
			ch=0;
			break;
		}	
		printf("\nEnter choice\n");
		scanf("%d",&ch);
	}
}
