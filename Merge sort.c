#include<stdio.h>
#define MAX 6
void splitlist(int arr[],int lb,int ub);
void merging(int arr[],int lb1, int ub1, int lb2,int ub2);
int main()
{
	int arr[MAX]={5,8,7,6,3,4};
	int i,j,n;
	n=sizeof(arr)/sizeof(int);
	printf("\n List before swapping:-");
	for (i=0;i<n;i++)
	{
		printf("%d,",arr[i]);
	}
	splitlist(arr,0,n-1);
	printf("\n List after swapping:-");
	for (i=0;i<n;i++)
	{
		printf("%d,",arr[i]);
	}
	return 0;
}
void splitlist(int arr[],int lb,int ub)
{
	int mid;
	mid=(lb+ub)/2;
	if (lb<ub)
	{
		splitlist(arr,lb,mid);
		splitlist(arr,mid+1,ub);
		merging(arr,lb,mid,mid+1,ub);
	}
}
void merging(int arr[],int lb1,int ub1,int lb2,int ub2)
{
	int lower1,lower2,AuxIdx,i;
	int Aux[MAX];
	AuxIdx=lb1;
	lower1=lb1;
	lower2=lb2;
	while(lower1<=ub1&&lower2<=ub2)
	{
		if (arr[lower1]<arr[lower2])
		{
			Aux[AuxIdx++]=arr[lower1];
			lower1++;
		}
		else
		{
			Aux[AuxIdx++]=arr[lower2];
			lower2++;
		}
	}
	while(lower1<=ub1)
	{
		Aux[AuxIdx++]=arr[lower1++];
	}
	while(lower2<=ub2)
	{
		Aux[AuxIdx++]=arr[lower2++];
	}
    for (i=lb1;i<=ub2;i++)
    {
    	arr[i]=Aux[i];
	}
}
