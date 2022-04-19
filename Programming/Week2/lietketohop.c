/*
### test case 1
    Please enter number k: 3
    Please enter number n: 5
    1 2 3 
    1 2 4
    1 2 5
    1 3 4
    1 3 5
    1 4 5
    2 3 4
    2 3 5
    2 4 5
    3 4 5
*/

#include <stdio.h>

int i,n,k;
int x[100];

void solution() 
{
    for ( i = 1; i <= k; i++) printf("%d ",x[i]);
    printf("\n");
    
}

int TRY (int m)
{
    int v;
    for (v= x[m-1] + 1; v <= n-k+m; v++) 
    {
        x[m]=v;
        if ( m == k) solution();
        else TRY(m+1);
    }
}

int main() 
{
    printf("Please enter number k: ");
    scanf("%d",&k);
    printf("Please enter number n: ");
    scanf("%d",&n);
    x[0]=0;
    TRY(1);
}

