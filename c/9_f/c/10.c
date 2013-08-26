#include <stdio.h>

void main()
{
	FILE* fp = fopen("./data.txt", "w");

	//char c = 0x7f;

/*
	fputc(c, fp);
	fputc('a', fp);
	fputc('b', fp);

	fseek(fp, 0, SEEK_SET);
*/
	int i;
	while ((i = fgetc(fp)) != EOF)
		printf("%x\n", i);
}


