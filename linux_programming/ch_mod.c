#include<stdio.h>
#include<sys/stat.h>
int main()
{
    int i;
    i=chmod("gow2",0777);
    printf("%d ",i);
}
