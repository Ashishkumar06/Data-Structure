#include<malloc.h>
#include<stdio.h>
struct linkedlist
{
	int info;
	struct linkedlist*next;
} *start,*head;
void reverse(struct linkedlist* start)
{
	if(start->next!=NULL)
	{
		start=start->next;
		reverse(start);
	}
	printf("%d",start->info);
}
int main()
{ 
	start=NULL;
	int i;
	for(i=0;i<=5;i++)
	{
		//First node is created
		if(start==NULL)
		{
			start=(struct linkedlist*)malloc(sizeof(struct linkedlist));
			head=start;
			printf("Enter first node information");
			scanf("%d",&(start->info));
		} //Other nodes are created
		else
		{
			start->next=(struct linkedlist*)malloc(sizeof(struct linkedlist));
			start=start->next;
			printf("Enter other node information");
			scanf("%d",&start->info);
		}
	}
	start->next=NULL;
	start=head;
	reverse(start);
}
/*void reverse(struct linkedlist* start)
{
	if(start->next!=NULL)
	{
		start=start->next;
		reverse(start);
	}
	printf("%d",start->info);
}*/
	
