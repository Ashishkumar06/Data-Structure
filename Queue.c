#include<stdio.h>
void QInsert(int Queue[],int *Front,int *Rear,int MAX,int ITEM)
{
	if((*Front==0 && *Rear==MAX)||(*Front==*Rear+1))
	{
		printf("\nQueue is Full");
		return;
	}
	if(*Rear==MAX) *Rear=0;
	else if(*Rear==-1)
	{
		*Front=0;
		*Rear=0;
	}
	else (*Rear)++;
	Queue[*Rear]=ITEM;
}
int QDelete(int Queue[],int *Front,int *Rear,int MAX)
{
	int item;
	if(*Front==-1)
	{
		printf("\nQueue is empty");
		return;
	}
	item=Queue[*Front];
	if(*Front==MAX) *Front=0;
	else if(*Front==*Rear)
	{
		*Front=-1;
		*Rear=-1;
	}
	else (*Front)++;
	return item;
}
void Display(int Queue[], int Front, int Rear, int MAX)
{
	int i;
	printf("\n");
	if (Front<=Rear)
	{
		for(i=Front;i<=Rear;i++)
		{
			printf("%d",Queue[i]);
		}
	}
	else
	{
		for(i=Front;i<=MAX;i++)
		{
			printf("%d",Queue[i]);
		}
		for(i=0;i<=Rear;i++)
		{
			printf("%d",Queue[i]);
		}
	}
}
void main()
{
	int Queue[5],MAX=4,item,Front=-1,Rear=-1;
	int choice=1;
	while(choice<3)
	{
		printf("\nInsert:\t 1: ");
		printf("\nDelete:\t 2: ");
		printf("\nDisplay:3:  ");
		printf("\n EXIT:\t 4: ");
		scanf("%d",&choice);
		if (choice==1)
		{
			printf("\nEnter item");
			scanf("%d",&item);
			QInsert(Queue,&Front,&Rear,MAX,item);
			Display(Queue,Front,Rear,MAX);
		}
		if(choice==2)
		{
			item=QDelete(Queue,&Front,&Rear,MAX);
			if (item!=-1)
			{
				printf("\nitem popped :  %d",item);
				Display(Queue,Front,Rear,MAX);
			}
		}
		if(choice==3) Display(Queue,Front,Rear,MAX);;
		if(choice==4) break;
	}
}
