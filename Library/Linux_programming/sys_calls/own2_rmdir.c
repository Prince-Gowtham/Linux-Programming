#include<unistd.h>
#include<stdio.h>
int main()
{
	int ret_val;
	ret_val=rmdir("ram");
	printf("ret_val = %d\n",ret_val);
}
