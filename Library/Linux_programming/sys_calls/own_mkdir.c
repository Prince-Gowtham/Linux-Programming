#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main()
{
	int ret_val;
	ret_val = mkdir("my_own2", 0664);
	printf("ret_val = %d\n", ret_val);
}
