#include <stdio.h>

struct xx 
{
	char c;
	int * p;
	float f;
};

void main()
{
	int i = 100;

	struct xx a;
	a.c = 'a';
	a.p = &i;
	a.f = 3.14159;
}


