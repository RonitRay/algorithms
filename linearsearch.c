#include <stdio.h>

int linSer(int a[],int n, int k)
{
	int i;
	for(i=0;i<n;i++)
	{
		 if(a[i]==k)
		 	return i;
	}
	return -999;
}

void main()
{
	int n;
	int a[]={4,2,1,3,5};
	int c=linSer(a,5,1);
	printf("(Found 1 at: )%d\n", c);
}