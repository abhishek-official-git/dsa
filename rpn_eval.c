#include "int_stack.c"
#include<stdbool.h>
#include<string.h>
#include<math.h>

int main()
{
	int res;
	char y[20];
	printf("Enter the expresson!\n");
	scanf("%s",y);
	stack *s1=NULL;
	for(int i=0;i<strlen(y);i++)
	{
		if(y[i]>=48 && y[i]<=57)
		{
			printf("\nInside if\n");
			s1=push(s1,(y[i]-48));
			printf("Pushed -> %d\n",(y[i]-48));
		}
		else
		{
			printf("Inside Else\n");
			int b=peep(s1);
			printf("b=%d\n",b);
			s1=pop(s1);
			int a=peep(s1);
			printf("a=%d\n",a);
			s1=pop(s1);
			switch(y[i])
			{
				case '*':
				res=a*b;
				break;

				case '/':
				res=a/b;
				break;

				case '^':
				res=pow(a,b);
				break;

				case '%':
				res=a%b;
				break;

				case '+':
				res=a+b;
				printf("res = %d",res);
				break;

				case '-':
				res=a-b;
				break;
			}
			printf("  res = %d",res);
			s1=push(s1,res);
		}
	}
	printf("\n%d",res);

}