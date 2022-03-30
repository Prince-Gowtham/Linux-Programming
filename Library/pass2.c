#include<stdio.h>
int fun(int a,int b);
int main()
{
    int a=20,b=20,c;
    c=fun(a,b);
    printf("%d\n",c);
}
int fun(int a,int b)
{
    return (a+b);
}
