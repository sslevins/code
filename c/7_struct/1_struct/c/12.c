#include <stdio.h>

union xx
{
	char a;
	char b;
};

void main()
{
	union xx test;

	test.a = 'a';
	test.b = 'b';

	printf("%c\n", test.a);
}
