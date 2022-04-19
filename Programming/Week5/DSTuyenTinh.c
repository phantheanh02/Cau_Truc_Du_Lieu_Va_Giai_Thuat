#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[10000],i,n=100;
void SinhMang()
{
    time_t t;
//    srand((unsigned) time(&t));
    for (i=0; i<n; i++) 
        a[i] = i;
}

void insert(int x, int p)
{
    for (i= n-1; i>= p; i--)
        a[i+1] = a[i];
    a[p] = x; 
    n++;
}

void delete(int p)
{
    for (i= p+1; i<= n-1; i++)
        a[i-1] = a[i];
    n--; 
}

void locate(int x)
{
    for (i=0; i<= n-1; i++)
        if (a[i] == x) 
        {
            printf("Locate of %d is %d",x,i);
            return i;
        }
    printf("No find!!!");
}

int main()
{
    int x,y;
    // Tạo ngẫu nhiên mảng 100 phần tử
    SinhMang();

    // Thêm phần tử 3 vào vị trí thứ 3
    do {
        printf("Locate wants add: ");
        scanf("%d",&x);
    } while (x <0 || x>n);
    printf("Value: ");
    scanf("%d",&y);
    insert(x,y);

    // Xóa 50 phần tử ngãu nhiên
    for (i=0; i<50; i++)
        delete(i);
        
    // Chỉ ra vị trí của phần tử có giá trị 5
    locate(5);
    return 0;
}