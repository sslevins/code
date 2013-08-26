#include <stdio.h>

void main(int argc, char* argv[])
{
	int c = 0;

	if (argc < 3)
		return;

	char* from = argv[1];
	char* to = argv[2];

	FILE* from_f = fopen(from, "r");
	FILE* to_f = fopen(to, "w");


	while ((c = fgetc(from_f)) != EOF)
	{
		fputc(c, to_f);
	}


	fclose(from_f);
	fclose(to_f);
}
