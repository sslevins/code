#include <stdio.h>

struct xx 
{
	char c;
	int i;
	long long ll;
};

union yy
{
	char arr[16];
	struct xx s;
};

void main()
{
	union yy hello;

	int i = 0;
	for (i = 0; i < 16; i++)
		hello.arr[i] = 0x00;

	hello.s.c = 'a';
	hello.s.i = 16;
	hello.s.ll = 32;

	for (i = 0; i < 16; i++)
		printf("%p: %02x\n", 
			&(hello.arr[i]), hello.arr[i]);
}



