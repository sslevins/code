#include <stdio.h>

void do_it(float i)
{
	// float ret = i*i*i;
	// printf("result is %f\n", ret);

	printf("result is %f\n", i*i*i);
}

void main(void)
{
	float f = 0.0;
	printf("Please input a float num: ");
	scanf("%f", &f);

	do_it(f);
}


