/* 
### test case
Please enter number HAU: 4
2413
3142

*/
#include <stdio.h>

int i,n,x[100];

void solution() 
{
    for ( i = 1; i <= n; i++) printf("%d",x[i]);
    printf("\n");
    
}

int check(int v, int k)
{
    for ( i = 1; i <= k-1; i++)
    {
        if ( x[i] == v) return 0;
        if ( x[i] + i == v + k) return 0;
        if ( x[i] - i == v - k) return 0;
    }
    return 1;
    
}

void TRY(int k)
{
    int v;
    for ( v = 1; v <= n; v++)
    if (check(v,k))
    {
        x[k]=v;
        if (k == n) solution();
        else TRY(k+1);
    }
}

void main()
{
    printf("Please enter number HAU: ");
    scanf("%d",&n);
    TRY(1);
}