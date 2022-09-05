#include<malloc.h>
#include<stdio.h>
struct linkedlist
{
	int info;
	struct linkedlist*next;
} *start,*head;
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
			scanf("%d",&start->info);
		} //Other nodes are created
		else
		{
			start->next=(struct linkedlist*)malloc(sizeof(struct linkedlist));
			start=start->next;
			scanf("%d",&start->info);
		}
	}
	start->next=NULL;
	start=head;
	while(start)
	{
		printf("%d",start->info);
		start=start->next;
	}
}
