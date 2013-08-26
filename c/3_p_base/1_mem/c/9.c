#include <stdio.h>

void main()
{
	char* a;
	printf("char*:\n\t %08x\t", a); a++; printf("%08x \n", a);

	short* b;
	printf("short*:\n\t %08x\t", b); b++; printf("%08x \n", b);

	int* c;
	printf("int*:\n\t %08x\t", c); c++; printf("%08x \n", c);

	long* d;
	printf("long*:\n\t %08x\t", d); d++; printf("%08x \n", d);

	long long* e;
	printf("long long*:\n\t %08x\t", e); e++; printf("%08x \n", e);

	float* f;
	printf("float*:\n\t %08x\t", f); f++; printf("%08x \n", f);

	double* g;
	printf("double*:\n\t %08x\t", g); g++; printf("%08x \n", g);


	printf("\n%08x\n", g);
	g = g+10;
	printf("%08x\n", g);

}


