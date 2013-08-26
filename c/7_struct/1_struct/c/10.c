#include <stdio.h>

union xx
{
	char c;
	int i;
};

void main()
{
	union xx a;

	a.i = 0x59585756;

	printf("%c %08x\n", a.c, a.c);

}


