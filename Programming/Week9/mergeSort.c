#include <stdio.h>

void merge(int a[], int l, int m, int r)
{
    int i=l, j=m+1;
    int ta[1000];
    for (int k=l; k<=r; k++)
    {
        if (i > m) 
        {
            ta[k] = a[j];
            j++;
        }
        else if (j > r) 
        {
            ta[k] = a[i]; 
            i++;
        }
        else 
        {
            if (a[i] < a[j])
            {
                ta[k]= a[i];
                i++;
            }
            else 
            {
                ta[k]=a[j];
                j++;
            }
        }
    }
    for (int k=l; k<= r; k++) a[k]=ta[k];
}

void mergeSort( int a[], int L, int R)
{
    if(L < R)
    {
        int M = (L+R)/2;
        mergeSort(a,L,M);
        mergeSort(a,M+1,R);
        merge(a,L,M,R);
    }
}

int main()
{
    int a[10]={5,7,3,8,1,2,9,4,6};
    mergeSort(a,0,8);
    for (int i = 0; i < 9; i++)
        printf("%d ",a[i]);
    
}