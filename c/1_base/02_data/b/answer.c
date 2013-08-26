#include <stdio.h>

void main(void)
{
/*
 	// 1
	int i = 0;

	printf("Please input a ascii: ");
	scanf("%d", &i);

	printf("%c\n", i);
*/

/*
	// 2
	float f = 0.0;
	printf("Please input a float: ");
	scanf("%f", &f);
	printf("%f\n", f);
	printf("%e\n", f);
*/

	float num = 0;
	printf("Please input a num: ");
	scanf("%f", &num);

	float ret = num*1000/(3.0e-23);

	printf("%e\n", ret);

}



