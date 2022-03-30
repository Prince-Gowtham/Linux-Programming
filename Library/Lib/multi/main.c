#include "main.h"
int main()
{
	int inp_1, inp_2;
	scanf("%d%d", &inp_1, &inp_2);
	printf("add = %d\n", add(inp_1, inp_2));
	printf("sub = %d\n", sub(inp_1, inp_2));
	printf("mul = %d\n", mul(inp_1, inp_2));
	printf("div = %d\n", div(inp_1, inp_2));
}
