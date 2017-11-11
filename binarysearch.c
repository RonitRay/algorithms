#include <stdio.h>

int binSer(int a[],int n, int key)
{
	int mid;
	int low=0, high=n-1;
	while(low<high)
	{
		mid=(low+high)/2;
		if(a[mid]==key)
			return mid;
		else if(a[mid]>key)
			high=mid-1;
		else
			low=mid+1;
	}
	return -999;
}

void main()
{
	int n;
	int a[]={4,2,1,3,5};
	int c=binSer(a,5,1);
	printf("(Found 1 at: )%d\n", c);
}