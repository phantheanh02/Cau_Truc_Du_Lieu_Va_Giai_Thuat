#include <stdio.h>
int i,j;


void selectionSort( int a[], int n)
{
    int min;
    for (i=0; i<n; i++)
    {
        min=i;
        for (j=i+1; j<n; j++)
            if (a[j]<a[min]) min=j;
        int tmp = a[min];
        a[min] = a[i];
        a[i]=tmp;
    }
}

int main()
{
    int ARR[5]= {1,5,6,2,4};
    selectionSort(ARR,5);
    for (i = 0; i < 5; i++)
    {
        printf("%d",ARR[i]);
    }
    
}