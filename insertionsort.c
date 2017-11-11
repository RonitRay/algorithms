#include < stdio.h >
void insSort(int a[], int n) 
{
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) 
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void main() {
    int a[] = {5,3,2,4,1,6,9,8,7,10};
    insSort(a, 10);
}