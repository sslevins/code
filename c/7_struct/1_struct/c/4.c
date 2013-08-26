#include <stdio.h>

struct xx
{
	int i;
	char c;
	float f;
};

void main()
{
	struct xx a;
	a.i = 100;
	a.c = 'a';
	a.f = 3.14159;

	struct xx * p = NULL;
	p = &a;

	printf("%d\n", sizeof(p));

	printf("%d %d %d\n", a.i, p->i, (*p).i);
	printf("%c %c %c\n", a.c, p->c, (*p).c);
	printf("%f %f %f\n", a.f, p->f, (*p).f);
}



