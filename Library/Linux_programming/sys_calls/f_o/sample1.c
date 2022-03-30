#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int ret_op;
	ret_op = open("./sam1", O_RDONLY, 0644);
	printf("file_descriptor = %d\n", ret_op);
}
