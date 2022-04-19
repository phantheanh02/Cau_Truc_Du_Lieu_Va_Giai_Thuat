#include <stdio.h>
#include <math.h>

int i,j,n,marked[1000],a[1000],x[1000];
float c[1000][1000],f,f_min,cmin;
void process()
{
     if ( f + c[x[n]][x[1]] < f_min)
         f_min = f + c[x[n]][x[1]];
}
void TRY( int k)
{
     int v;
     for (v=1; v<=n; v++)
         if (marked[v] == 0) 
         {
             x[k] = v;
             f = f + c[x[k-1]][x[k]];
             marked[v] = 1;
             if (k == n) process();
             else 
             {
                 int g = f + cmin*(n-k+1);
                 if (g < f_min) TRY(k+1);
             }
             marked[v] = 0;
             f = f- c[x[k-1]][x[k]];
         }
}

void main ()
{
    f_min=99999;
    int v;
    int ToaDo[100][100];
    printf("Nhap so thanh pho: ");
    scanf("%d",&n);
    printf("Toa do cac thanh pho\n");
    for (v=1; v<=n; v++) 
        scanf("%d%d%d",&ToaDo[v][1],&ToaDo[v][2],&ToaDo[v][3]);
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
            c[j][i] = c[i][j]=
            sqrt(
                    (ToaDo[i][2]-ToaDo[j][2])*(ToaDo[i][2]-ToaDo[j][2]) 
                    + (ToaDo[i][3]-ToaDo[j][3])*(ToaDo[i][3]-ToaDo[j][3])
                );
    for (v=1; v<=n; v++) marked[v]=0;
    x[1] = 1;
    marked[1] = 1;
    TRY(2);
    for (i=1; i<=n; i++) printf("%d ",x[i]);
    printf("\nF_min = %d",f_min);
   
}