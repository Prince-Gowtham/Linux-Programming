#include<stdio.h>
int main()
{
    int a=10,b=20,x;
    fun(&a,&b);
    printf("%d\n",fun);
}
int fun(int *a,int *b)
{
    int *c;
    *c=*a+*b;
    return *c;
}
