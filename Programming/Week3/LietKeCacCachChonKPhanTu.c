// Liệt kê các cách chọn k phần tử mà khong có 2 phần tử đứng cạnh nhau
#include <stdio.h>

int n,k,i,dem=0,x[100];
void solution()
{
	for (i=1; i<=k; i++) printf("%d ",x[i]);
	printf("\n");
}
 
 
void TRY(int stt)
{
	int v;
	for (v=x[stt-1]+2; v<=n; v++)
	{
		x[stt]=v;
		if (stt != k) TRY(stt+1) ;
		else 
		{
			solution();
		}
	}
}

int main()
{
	printf("Nhap n (so phan tu): ");
	scanf("%d",&n);
	printf("Nhap k (so phan tu can in ra): ");
	scanf("%d",&k);
	x[0]=-1;
	TRY(1);
	return 0;
}
