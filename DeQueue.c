#include<stdio.h>
#define BEG 0
#define END 1
void QInsert(int Queue[],int *Front, int *Rear, int MAX, int Item, int side);
int QDelete(int Queue[],int *Front, int *Rear,int side);
void Display(int Queue[], int Front, int Rear);

void QInsert(int Queue[],int *Front, int *Rear, int MAX, int Item, int side)
{
    int i;
    if(*Front==0 && *Rear==MAX)
    {
        printf("\nQueue is full....");
        return;
    }
    if(*Front==-1)
    {
        *Front=0;
        *Rear=0;
        Queue[*Front]=Item;
        return;
    }
    if(side==BEG)
    {
        if(*Front==0)   // insert at begining
            {
                for(i=*Rear+1;i>*Front;i--)
                {
                    Queue[i]=Queue[i-1];
                }
                Queue[*Front]=Item;
                (*Rear)++;
            }
       else
       {
           (*Front)--;
           Queue[*Front]=Item;
       }
    }
    else
    {
          if(*Rear==MAX)
          {
              for(i=*Front-1;i<*Rear;i++)
                {
                    Queue[i]=Queue[i+1];
                }
                Queue[*Rear]=Item;
                (*Front)--;

          }
          else
          {
              (*Rear)++;
              Queue[*Rear]=Item;
          }
    }
}
int QDelete(int Queue[],int *Front, int *Rear,int side)
{
    int Item;
    if(*Front==-1)
    {
        printf("\nQueue is empty.....");
        return -1;
    }

    if(*Front==*Rear)
    {
        Item=Queue[*Front];
        *Front=-1;
        *Rear=-1;
        return Item;
    }
    if(side==BEG)
    {
        Item=Queue[*Front];
        (*Front)++;
        return Item;
    }
    else
    {
        Item=Queue[*Rear];
        (*Rear)--;
        return Item;
    }
}
void Display(int Queue[], int Front, int Rear)
   {
       printf("\n");
       int i;
       if(Front>-1)
       for(i=Front;i<=Rear;i++) printf("%d, ",Queue[i]);
   }

int main()
    {
        int Queue[5],MAX=4,Item,Front=-1,Rear=-1;
        int choice=1,side;
        while(choice<=3)
        {
            printf("\nInsert:\t 1:  ");
            printf("\nDelete:\t 2:  ");
            printf("\nDisplay:3:  ");
            printf("\nEXIT:\t 4:  ");
            scanf("%d",&choice);
            if(choice==1)
            {
                printf("\nEnter 0 to operate at beginning and 1 to operate at last");
                scanf("%d",&side);
                if(side>0) side=END;
                printf("\nEnter item ");
                scanf("%d",&Item);
                QInsert(Queue,&Front,&Rear,MAX,Item,side);
                Display(Queue,Front,Rear);
            }
            if(choice==2)
            {
                printf("\nEnter 0 to operate at beginning and 1 to operate at last");
                scanf("%d",&side);
                if(side>0) side=END;
                Item=QDelete(Queue,&Front,&Rear,side);
                if(Item!=-1)
                {
                    printf("\nitem popped :  %d",Item);
                    //printf("\nFront=%d, Rear=%d",Front,Rear);
                    Display(Queue,Front,Rear);
                }
            }
            if(choice==3) Display(Queue,Front,Rear);
            if(choice==4) break;
        }
    return 0;
}
