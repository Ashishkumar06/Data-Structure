#include<stdio.h>
void Quick(int arr[],int n);
void Quicksort(int arr[],int BEG,int END,int *LOC);
int main()
{
	int arr[]={40,1,8,9,3,0,5,6,2,7};
	int i,j,n;
	n=sizeof(arr)/sizeof(int);
	printf("\n List before sortings: ");
	for(i=0;i<n;i++)
	{
		printf("%d,",arr[i]);
	}
	Quick(arr,n);
	printf("\nList after sortings: ");
	for(i=0;i<n;i++)
	{
		printf("%d,",arr[i]);
	}
	return 0;
}
void Quick(int arr[],int n)
{
	int LOC,BEG,END;
	int LOWER[n],UPPER[n],TOP=0;
	LOWER[0]=0;
	UPPER[0]=n-1;
	while(TOP>-1)
	{
		BEG=LOWER[TOP];
		END=UPPER[TOP];
		TOP--;
		Quicksort(arr,BEG,END,&LOC);
		if(BEG<LOC-1)
		{
			TOP++;
			LOWER[TOP]=BEG;
			UPPER[TOP]=LOC-1;
			
		}
		if(END>LOC+1)
		{
			TOP++;
			LOWER[TOP]=LOC+1;
			UPPER[TOP]=END;
		}
	}
}
void Quicksort(int arr[],int BEG,int END,int *LOC)
{
	int LEFT=BEG,temp,RIGHT=END;
	while(RIGHT>LEFT)
	{
		*LOC=LEFT;
		while(arr[*LOC]<arr[RIGHT]&&*LOC<RIGHT) RIGHT--;
		if(arr[*LOC]>arr[RIGHT])
		{
			temp=arr[*LOC];
			arr[*LOC]=arr[RIGHT];
			arr[RIGHT]=temp;
		}
	}
	*LOC=RIGHT;
	while(arr[LEFT]<arr[*LOC]&&*LOC>LEFT) LEFT++;
	if(arr[LEFT]>arr[*LOC])
	{
		temp=arr[*LOC];
		arr[*LOC]=arr[LEFT];
		arr[LEFT]=temp;
	}
	return;
}
