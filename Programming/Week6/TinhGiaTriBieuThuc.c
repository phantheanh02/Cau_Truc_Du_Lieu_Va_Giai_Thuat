#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
int stack[1000];
int top;

int eval(char *s)
{
    char *ptr;
    int first, second, c;
    ptr=strtok(s,"");
    top=-1;
    while (ptr)
    {
        if (isop(*ptr))
        {
            second= pop();
            first=pop();
            c=do_op(first,second,*ptr);
            push(c);
        }
        else
        {
            c=atoi(ptr);
            push(c);
        }
        ptr=strtok(NULL,"");
    }
    return (pop());
}

int do_op (int a, int b, char op)
{
    int ans;
    switch (op)
    {
    case '+':
        ans =a+b;
        break;
    case '-':
        ans=a-b;
        break;
    case '*':
        ans=a*b;
        break;
    
    }
    return ans;
}

int pop(void)
{
    int ret;
    ret = stack[top];
    top--;
    return ret;
}

int push(int a)
{
    top++;
    stack[top]=a;
}

int isop(char op)
{
    if (op == '+' || op == '-' || '*' ) return 1;
    else return 0;
}

int main(void)
{
    char expre[80];
    int value;
    printf("Nhap vao xau bieu thuc: ");
    fflush(stdin);
    gets(expre);
    value=eval(expre);
    printf("Gia tri cua bieu thuc: %i",value);
    return 0;
}