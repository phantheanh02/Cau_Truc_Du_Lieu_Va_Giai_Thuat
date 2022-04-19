/* Chương trình liệt kê các xâu nhị phân độ dài n trong đó không có 3 bit 1 nào dứng cạnh nhau
 test case
Do dai chuoi nhi phan: 4
0000
0001
0010
0011
0100
0101
0110
1000
1001
1010
1011
1100
1101
*/
#include <stdio.h>

int i,n,x[1000];

void solution()
{
    for (i=1; i<=n; i++)  printf("%d",x[i]);
    printf("\n");

}

int check(int stt, int v)
{
    if (x[stt-1] == 1 && x[stt-2] ==1 && v == 1) return 0;
    else return 1;
}

void TRY(int stt)
{
    int v;
    for (v=0; v<=1; v++) 
    if (check(stt,v)) 
    {
        x[stt]=v;
        if (stt == n) solution();
        else TRY(stt+1);
    }
}

void main()
{
    do 
    {
        printf("Nhap do dai xau nhi phan: ");
        scanf("%d",&n);
    } while (n<1);
    for (i=1; i<=n; i++) x[i]=0;
    TRY(1);
}