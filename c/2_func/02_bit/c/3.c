#include <stdio.h>

void main()
{
	int i = 0x8000ff00;

	//printf("%08x\n", i<<5);
	
	printf("%08x\n", i>>1);
}
