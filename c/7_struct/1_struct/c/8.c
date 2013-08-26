#include <stdio.h>

struct xx
{
	char c;
	int i;
	float f;
};

void main()
{
	struct xx a = {'a', 100, 3.14};
	struct xx b = a;
	struct xx c;
	c = a;

	printf("%d\n", c.i);
}
