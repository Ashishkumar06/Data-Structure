#include<stdio.h>
#include<malloc.h>
struct linkedlist
{
	int info;
	struct linkedlist*next;
}*start,*head;
void deletenode(struct linkedlist*start,int info)
{
	if(start->info==info)
	{
		head=start->next;
		return;
	}
	while(start!=NULL)
	{
		if(start->next->info==info)
		{
			start->next=start->next->next;
			break;
		}
		start=start->next;
	}
}
void traverse(struct linkedlist*start)
{
	while(start)
	{
		printf("%d,  ",start->info);
		start=start->next;
	}
}
int main()
{
	start=NULL;
	int i,delete;
	for(i=0;i<5;i++)
	{
		if(start==NULL)
		{
			start=(struct linkedlist*)malloc(sizeof(struct linkedlist));
			head=start;    //Create first node
			printf("Enter first number");
			scanf("%d",&(start->info));
		}
		else
		{
			//Other nodes are created
			start->next=(struct linkedlist*)malloc(sizeof(struct linkedlist));
			start=start->next;
			printf("Enter other node information");
			scanf("%d",&start->info);
		}
	}
	start->next=NULL;
	start=head;
	deletenode(start,4);
	traverse(start);
}

