#include "stack.c"
#include<stdbool.h>
#include<string.h>

bool getPrec(char a,char b)
{
	//a=upper b=lower
	int x,y;
	if(a==')' && b!='(')
		return false;//because ')' got highest precedency as per my logic.
	else if(a==')' && b=='(')// but ')' can only function upto (.
		return true;

	if(a=='(' || b=='(')
		return true;
	
	switch(a)
	{
		case '(':
		x=0;
		break;
		case '*':
		case '/':
		case '^':
		case '%':
		x=2;
		break;
		case '+':
		case '-':
		x=1;
		break;
	}
	switch(b)
	{
		case '(':
		y=0;
		break;
		case '*':
		case '/':
		case '^':
		case '%':
		y=2;
		break;
		case '+':
		case '-':
		y=1;
		break;
	}
	if(x>y)
		return true;
	else
		return false;
}

int main()
{
	stack *s1=NULL;	
	char x[20],y[20];
	printf("Enter the expression!\n");
	scanf("%s",x);
	int c=0;
	int l=strlen(x);
	x[l]=')';
	s1=push(s1,'(');
	int i=0;
	while(s1!=NULL)
	{
		if(x[i]>=48 && x[i]<=57)
		{
			y[c]=x[i];
			c++;
		}
		else
		{
			char t=peep(s1);
			if(getPrec(x[i],t)==true)
			{
				if(x[i]!=')')
				s1=push(s1,x[i]);
				else
				s1=pop(s1);
			}					
			else
			{
				while(getPrec(x[i],t)==false && s1!=NULL)
				{
					y[c]=t;
					c++;
					s1=pop(s1);
					t=peep(s1);
				}
				if(x[i]!=')')
				s1=push(s1,x[i]);
				else
				s1=pop(s1);
			}
		}
		i++;
	}
	printf("%s",y);
}