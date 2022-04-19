/* ### Test case 1
    Chuong trinh tinh C(k,n)
    Nhap so k: 5  
    Nhap so n: 10
    C(5,10) = 252

   ### test case 2
    Chuong trinh tinh C(k,n)
    Nhap so k: 5 
    Nhap so n: 5
    C(5,5) = 1  
*/


#include <stdio.h>
int m[100][100];
int i,j;

int C(int k, int n) 
{
    if (k == 0 || k == n)
    m[k][n] = 1;
    else if (m[k][n] < 0)
        m[k][n] = C(k-1,n-1) + C(k,n-1);
    return m[k][n];
}

int main() 
{
    int k,n;
    printf("Chuong trinh tinh C(k,n)\n");
    printf("Nhap so k: ");
    scanf("%d",&k);
    printf("Nhap so n: ");
    scanf("%d",&n);
    for (i=0; i<100; i++) 
        for ( j = 0; j < 100; j++)
            m[i][j]=-1;
    printf("C(%d,%d) = %d",k,n,C(k,n));
    return 0;
        
}