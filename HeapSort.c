#include<stdio.h>

void MaxHeap(int arr[],int n)
{
    int i=1,par,child,item;
    while(i<n)
    {
        child=i;
        par=(i-1)/2;
        item=arr[child];
        while(child>0 && item>arr[par])
        {
            printf("\nChild=%d, Par=%d",child,par);
            arr[child]=arr[par];
            child=par;
            par=(child-1)/2;
        }
        arr[child]=item;
        i++;
        /*printf("\n");
        for(int i=0;i<n;i++)
        {
           printf("%d, ",arr[i]);
        }
        printf("\n*******************");*/
    }
}
void MinHeap(int arr[], int n)
{
    int item,i,j,k,child,par;
    for(i=n-1;i>1;i--)
    {
        item=arr[i];
        arr[i]=arr[0];
        child=1;
        par=0;
        if(arr[child+1]>arr[child]) child++;
        while(child<=i-1)
        {
            arr[par]=arr[child];
            par=child;
            child=(2*par)+1;
            if(child<=i-1 && arr[child+1]>arr[child]) child++;
        }
        arr[par]=item;
         printf("\n");
        for(j=0;j<n;j++)
        {
           printf("%d, ",arr[j]);
        }
        printf("\n*******************");
    }
}
int main()
{
     int arr[]={172,101,122, 90, 98, 84, 99, 47, 40, 71, 77, 70, 78, 79, 76};//{1,2,3,4,5,6,7,8};
     int n=sizeof(arr)/sizeof(int);
     int i;
     printf("\nList before creating MaxHeap:  ");
     for(i=0;i<n;i++)
     {
         printf("%d, ",arr[i]);
     }
     MaxHeap(arr,n);
     printf("\nList after creating MaxHeap:  ");
     for(i=0;i<n;i++)
     {
         printf("%d, ",arr[i]);
     }
     MinHeap(arr,n);
     printf("\nList after creating MinHeap:  ");
     for(i=0;i<n;i++)
     {
         printf("%d, ",arr[i]);
     }
     return;
}
