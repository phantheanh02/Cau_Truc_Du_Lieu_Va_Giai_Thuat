#include <stdio.h>

int partition(int a[], int L, int R, int indexPivot)
{
    int pivot = a[indexPivot];
    int tg;
    tg=a[indexPivot];
    a[indexPivot]=a[R];
    a[R]=tg;

    int storeIndex = L;
    for (int i=L; i<R; i++)
        if (a[i] < pivot)
        {
            tg=a[storeIndex];
            a[storeIndex] = a[i];
            a[i]=tg;
            storeIndex++;
        }
    tg=a[storeIndex];
    a[storeIndex] = a[R];
    a[R]=tg;
    return storeIndex;
}

void quickSort(int a[], int L, int R)
{
    if (L < R)
    {
        int index = (L+R)/2;
        index = partition(a,L,R,index);
        if (L < index) quickSort(a,L,index-1);
        if (index < R) quickSort(a,index+1,R);
    }
}

int main()
{
    int a[10]={5,7,3,8,1,2,9,4,6};
    quickSort(a,0,8);
    for (int i = 0; i < 9; i++)
        printf("%d ",a[i]);
    
}