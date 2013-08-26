#include <stdio.h>
#include <stdarg.h>

void do_it(int i, ...)
{
	int temp;

	va_list ap;

	va_start(ap, i);

	while (i--)
	{
		temp = va_arg(ap, int);	
		printf("%d ", temp);
	}
	printf("\n");

	va_end(ap);
}

void main()
{
	do_it(5, 1, 2, 3, 4, 5);
	do_it(4, 1, 2, 3, 4);
	do_it(3, 1, 2, 3);
	do_it(2, 1, 2);
	do_it(1, 1);
	do_it(0);

	printf("%d %d %d %d\n", 1, 2, 3, 4);
	printf("%d %d %d \n", 1, 2, 3);
	printf("%d %d \n", 1, 2);
	printf("%d \n", 1);

}


