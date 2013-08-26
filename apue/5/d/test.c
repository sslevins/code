#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#define PRINT_CHAR 0
#define TRIPLE_INT 1
#define ADD_CHAR 2

struct x
{
	char a;
	char b;
};

union u
{
	int i;
	struct x x;
};

void do_it(char * s, int cmd, ...)
{
	union u * p;

	va_list ap;

	va_start(ap, cmd);

	switch (cmd)
	{
		case PRINT_CHAR:
			printf("%s\n", s);

			break;

		case TRIPLE_INT:
			p = (union u *)va_arg(ap, int);
			printf("%s %d\n", s, 3*p->i);

			break;

		case ADD_CHAR:
			p = (union u *)va_arg(ap, int);
			printf("%s %c%c\n", s, p->x.a, p->x.b);

			break;

		default :
			printf("default\n");
	}

	va_end(ap);
}

int main()
{
	do_it("hello", PRINT_CHAR);		// hello

	union u a;
	a.i = 10;
	do_it("good", TRIPLE_INT, &a);	// good 30

	union u b;
	b.x.a = 'a';
	b.x.b = 'b';
	do_it("bye", ADD_CHAR, &b); // bye ab
}





