#include <stdio.h>

// fd --> FILE *		fdopen();
// FILE * --> fd		fileno();

int main()
{
	printf("%d\n", fileno(stdin));
	printf("%d\n", fileno(stdout));
	printf("%d\n", fileno(stderr));

	FILE* f1 = fdopen(0, "r");
	FILE* f2 = fdopen(1, "w");
	FILE* f3 = fdopen(2, "w");

	fprintf(f2, "hello world!\n");
}
