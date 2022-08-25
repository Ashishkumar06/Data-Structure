#include<stdio.h>
#include<string.h>
void PUSH(char STACK[],int *TOP,int MAXSTIK,char ITEM)
{
	if (*TOP==MAXSTIK)
	{
		return;
	}
	(*TOP)++;
	STACK[*TOP]=ITEM;
}
char POP(char STACK[],int *TOP)
{
	char item;
	if(*TOP==-1)
	{
		return -1;
	}
	item=STACK[*TOP];
	(*TOP)--;
	return item;
}
int getPrec(char ch)
{
	if(ch=='(')return 0;
	if(ch=='+'|| ch=='-') return 1;
	if(ch=='*'||ch=='/'||ch=='%') return 2;
	if(ch=='$'||ch=='^') return 3;
}
void addBrackets(char str[])
{
	int i,j;
	char s1[]=")";
	char s2[100]="(";
	strcat(str,")");
	strcat(s2,str);
	strcpy(str,s2);
}
int main()
{
	char infix[100]="(((A+B)*C+D)/(E+F+G))";
	char postfix[100];
	char symbol,item;
	char STACK[50];
	int TOP=-1,MAX=99;
	int i=-1,k=0;
	int rank;
	addBrackets(infix);
	printf("\nThe given infix expression is : %s",infix);
	while(infix[++i]!='\0')
	{
		symbol=infix[i];
		if (symbol=='(') PUSH(STACK,&TOP,50,symbol);
		else if(symbol==')')
		{
			while((item=POP(STACK,&TOP))!='('&&TOP>-1) postfix[k++]=item;
		}
		else if (symbol=='+'|| symbol=='-'|| symbol=='*'||symbol=='/'||symbol=='%'||symbol=='$'||symbol=='^')
		{
			while(getPrec(STACK[TOP])>=getPrec(symbol)&&TOP>-1)
			{
				postfix[k++]=POP(STACK,&TOP);
			}
			PUSH(STACK,&TOP,MAX,symbol);
		}
		else postfix[k++]=symbol;
	}
	printf("\n The postfix expression is :");
	for(i=0;i<k;i++) printf("%c",postfix[i]);
}
