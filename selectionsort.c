#include <stdio.h>
void selSort(int a[], int n)
{
	int i,j,min,pos,t;
	for(i=0;i<n-1;i++)
	{
		min=a[i]; 
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<min)
			{
				min=a[j];
				pos=j;
			}
		}
		t=a[i];
		a[i]=a[pos];
		a[pos]=t;
	}

	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}

void main()
{
	int a[]={5,3,2,4,1,6,9,8,7,10};
	selSort(a,10);
}

