#include <stdio.h>
void bubbleSort(int a[], int n)
{
   int i, j, t;
   for (i = 0; i < n-1; i++)      
      for (j = 0; j < n-i-1; j++) 
        if (a[j] > a[j+1])
        {
            t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
        }
}
 
int main()
{
    int a[] = {5,3,2,4,1};
    int n = sizeof(a)/sizeof(a[0]);
    bubbleSort(a, n);
    printf("Sorted array: \n");
    int i;
    for (i=0; i < n; i++)
        printf("%d ", a[i]);  
    return 0;
}