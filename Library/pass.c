#include<stdio.h>
int main()
{
    int a,b,c;
    a=20;
    b=30;
    c=add(a,b);
    printf("%d ",c);
}
int add(int a,int b)
{
    return(a+b);
}
