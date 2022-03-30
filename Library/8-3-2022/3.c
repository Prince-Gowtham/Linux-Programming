#include<stdio.h>
//#include<math.h>
#include"power.h"
#include"cube.h"
int main()
{
	int a = 100;
	double squareroot,cbe;
	squareroot = pow(a,2);
	cbe = cube(a);
	printf("%lf\n",cbe);
	printf("%lf\n",squareroot);
}
