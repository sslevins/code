#include <stdio.h>

typedef unsigned int u32;

struct {
	int i;
	char c;
	float f;
} hello, world;

//struct xx hello;
//struct xx world;

typedef struct {
	int i;
	char c;
	float f;
} XX;


void main()
{
	u32 i = 100;

	struct xx good;
	struct xx bye;

	XX good;
	XX bye;

	printf("%d\n", i);

}




