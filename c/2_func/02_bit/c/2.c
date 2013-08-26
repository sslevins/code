#include <stdio.h>

void main(void)
{
	int i = 0xff00ff00;
	int j = ~i;

	int k = i&j;

	printf("%08x\n", i);
	printf("%08x\n", j);
	printf("%08x\n", k);

	printf("\n\n");

	i = 0x00ffff00;
	k = i|j;
	printf("%08x\n", i);
	printf("%08x\n", j);
	printf("%08x\n", k);

	printf("\n\n");

	i = 0xff0000ff;
	j = 0x0ff0f0f0;
	k = i^j;
	printf("%08x\n", i);
	printf("%08x\n", j);
	printf("%08x\n", k);


}





