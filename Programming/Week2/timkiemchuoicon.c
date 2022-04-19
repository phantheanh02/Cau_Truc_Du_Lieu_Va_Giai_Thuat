#include <stdio.h>

int i,j;

// Thuật toán với độ phức tạp O(n)
void On1(int a[], int n) 
{
    int sum=0, max=-10000, fistnumber=0, lastnumber;
    for (i=0; i<n; i++) 
    {
        if (sum+a[i] >= a[i])  sum+=a[i];
        else  
        {
            sum=a[i];
            fistnumber=i;
        }
        if (sum > max) 
        {
            max=sum;
            lastnumber=i;
        }
    }
    
    printf ("\nDay co trong so lon nhat theo O(n^1): ");
    for (i = fistnumber; i <= lastnumber; i++)
    printf("%d ",a[i]);
}


// Thuật toán với độ phức tạp O(n^2)
void On2(int a[], int n) 
{
    int fistnumber, lastnumber;
    int sum=0, max=-10000;
    for (i=0; i<n; i++) 
    {
        sum=0;
        for ( j = i; j < n; j++)
        {
            sum+=a[j];
            if (sum >= max) 
            {
                max=sum;
                fistnumber=i;
                lastnumber=j;
            }
        }
        
    }
    printf ("\nDay co trong so lon nhat theo O(n^2): ");
    for (i = fistnumber; i <= lastnumber; i++)
    printf("%d ",a[i]);
}

// Thuật toán với độ phức tạp O(n^3)
void On3    (int a[], int n) 
{
    int fistnumber, lastnumber,k;
    int sum=0, max=-10000;
    for ( i = 0; i < n; i++)
        for (j=i; j<n; j++) 
        {
            sum=0;
            for (k=i; k<=j; k++) sum+=a[k];
            if (sum > max) 
            {
                max=sum;
                fistnumber=i;
                lastnumber=j;
            }
        }
    printf ("\nDay co trong so lon nhat theo O(n^3): ");
    for (i = fistnumber; i <= lastnumber; i++)
    printf("%d ",a[i]);
}

// main
int main() 
{
    int n, a[1000];
    printf("Nhap so phan tu cua day\n ");
    scanf("%d",&n);
    printf("Nhap cac phan tu cua day\n");
    for ( i = 0; i < n; i++) scanf("%d",&a[i]);
    On1(a,n);
    On2(a,n);
    On3(a,n);
}