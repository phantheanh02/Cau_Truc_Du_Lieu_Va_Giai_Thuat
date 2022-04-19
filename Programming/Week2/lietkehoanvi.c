/*
### test case 1
    Please enter number n: 2
    12
    21
    
### test case 2
    Please enter number n: 3
    123
    132
    213
    231
    312
    321
*/
#include <stdio.h>

int i,n,k;
int x[100], m[100];


void solution() 
{
    for ( i = 1; i <= n; i++) printf("%d",x[i]);
    printf("\n");
    
}

int TRY (int k)
{
    int v;
    for (v=  1; v <= n; v++) 
    if ( !m[v])
    {
       x[k] = v;
       m[v] = 1;
       if (k == n) solution();
       else TRY(k+1);
       m[v]=0;  
    }
    
}

int main() 
{
    printf("Please enter number n: ");
    scanf("%d",&n);
    for (i=1; i<=n; i++) m[i]=0;
    TRY(1);
}
