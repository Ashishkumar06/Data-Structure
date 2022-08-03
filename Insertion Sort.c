#include<stdio.h>
int main()
{
	int i,j,item,n[5]={2,5,6,8,7};
	for(i=1;i<5;i++)
	{
		item=n[i];
		for(j=i-1;j>=0&&item<n[j];j--)
		{
			n[j+1]=n[j];
		}
		n[j+1]=item;
	}
	for(i=0;i<5;i++)
	{
		printf("%d\n",n[i]);
	}
	return 0;
	
	
}
