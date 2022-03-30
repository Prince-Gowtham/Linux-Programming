#include<stdio.h>
#include<sys/stat.h>

int main()
{
	int ret_val;
	ret_val=chmod("muthu1", 0664);
	printf("ret_val = %d\n",ret_val);
}
