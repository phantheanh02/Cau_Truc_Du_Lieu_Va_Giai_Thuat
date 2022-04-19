#include <stdio.h>

int i,j,n,x[100][100],s[100][100];
void greedy3 ()
{
    int tg;
    // sắp xếp các đoạn trong X theo thứ tự không giảm của bi;
    for (i=1; i<=n; i++)
        for (j=i+1; j<=n; j++)
            if (x[i][2] > x[j][2])
            {
                tg = x[i][1];
                x[i][1] = x[j][1];
                x[j][1] = tg;

                tg = x[i][2];
                x[i][2] = x[j][2];
                x[j][2] = tg;
            }
    s[1][1]=x[1][1];
    s[1][2]=x[1][2];
    int dem=1,check;
    for (i=2; i<=n; i++) 
    {
        check=1;
        for (j=i-1; j>=1; j--)
        if (x[i][1] < s[j][2]) check=0;
        if (check != 0) 
        {
            dem++;
            s[dem][1]=x[i][1];
            s[dem][2]=x[i][2];
        }
    }
    printf("\nDap an\n");
    for (i=1; i<=dem; i++)
        printf("%d %d\n",s[i][1],s[i][2]);
}
int main()
{
    printf("Nhap so doan thang: ");
    scanf("%d",&n);
    printf("Nhap cac doan thang\n");
    for (i=1; i<=n; i++) scanf("%d%d",&x[i][1],&x[i][2]);
    greedy3();
    return 0;
}
