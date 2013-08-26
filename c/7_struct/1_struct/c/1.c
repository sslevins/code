#include <stdio.h>

struct xxxx 
{
	char c;
	int i;
	float f;
};

void main()
{
	int i;

	struct xxxx hello; 
	hello.c = 'a';
	hello.i = 100;
	hello.f = 3.14159;

	struct xxxx world = {'a', 100, 3.14159};

	printf("%d\n", hello.i);

	printf("%c\n", hello.c);

	printf("%f\n", hello.f);
}





