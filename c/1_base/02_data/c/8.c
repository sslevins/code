#include <stdio.h>

void main(void)
{
	float f = 123.45678;

	double d = 1234567.987654;

	printf("%f\n", f);

	printf("%e\n", f);
	printf("%e\n", d);

	printf("%d\n", sizeof(float));
	printf("%d\n", sizeof(double));

}
