#include<stdio.h>
void PUSH(int STACK[],int item,int *TOP,int MAX)
{
	if (*TOP==MAX)
	{
		printf("\n STACK OVERFLOW");
		return;
	}
	(*TOP)++;
	STACK[*TOP]=item;
}
int POP(int STACK[],int *TOP)
{
	int item;
	if (*TOP==-1)
	{
		printf("\n STACK UNDERFLOW");
		return;
	}
	item=STACK[*TOP];
	(*TOP)--;
	return item;
}
void PEEK(int STACK[],int *TOP)
{
	int i;
	for(i=0;i<=TOP;i++)
	{
		printf("%d",STACK[i]);
	}
}
int main()
{
	int TOP=-1,STACK[5],MAX=4,choice,item,b,i;

	while(1)
	{
			printf("\n The menu");
			printf("\n 1.Push the number");
			printf("\n 2.Pop the number");
			printf("\n 3.Peek the number");
			printf("\n4. exit ");
		printf("\nEnter choice");
		scanf("%d",&choice);
		if (choice==1)
		{
			  printf("Enter item");
			  scanf("%d",&item);
			   PUSH(STACK,item,&TOP,4);
		}
			if (choice==2)
			{
				b=POP(STACK,&TOP);
				printf("%d",b);
			}
			if (choice==3)
				{
					PEEK(STACK,TOP);
				}
			
			if(choice==4)
			{
				break;
			}
	}
}
