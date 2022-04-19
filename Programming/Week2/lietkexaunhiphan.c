/*
### test case 1
    Please enter number bits: 2
    00
    01
    10

### test case 2
    Please enter number bits: 3
    000
    001
    010
    100
    101
*/
#include <stdio.h>

int i,n;
int x[100];

void solution() 
{
    for ( i = 1; i <= n; i++) printf("%d",x[i]);
    printf("\n");
    
}

int TRY (int k)
{
    int v;
    
    for ( v = 0; v <= 1; v++)
    {
        if (x[k-1] + v < 2)
        {
            x[k] = v;
            if ( k == n)    solution();
            else TRY(k+1);  
        }
    }
}

int main() 
{
    printf("Please enter number bits: ");
    scanf("%d",&n);
    x[0]=0;
    TRY(1);
}