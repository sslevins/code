#include <stdio.h>

struct xx {
	char a; 	char b; 	char c; 	char d;
};

struct yy {
	int i;
};

void main()
{
	struct yy a; 		a.i = 0x51525354;

	struct yy *p = &a; 
	struct xx *q = NULL;

	q = p;

	printf("0x%x\n", a.i);
	printf("-----------\n");
	printf("%c %x\n", q->a, q->a);
	printf("%c %x\n", q->b, q->b);
	printf("%c %x\n", q->c, q->c);
	printf("%c %x\n", q->d, q->d);


}
