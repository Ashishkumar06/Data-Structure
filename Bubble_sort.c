#include<stdio.h>
int main()
{
	int i,j,temp,n[5]={8,1,7,4,2};
	/*for (i=0;i<5;i++)
	{
		printf("Enter numbers");
		scanf("%d",&n[i]);
	}*/
	for(i=1;i<5;i++)
	{
		for(j=0;j<5-i;j++)
		{
			if (n[j]>n[j+1])
			{
				temp=n[j];
				n[j]=n[j+1];
				n[j+1]=temp;
			}
		}
	}
	for(i=0;i<5;i++)
	{
		printf("Bubblesort-%d\n",n[i]);
	}
	//printf("%d",n[i]);
	return 0;
}
