#include <stdio.h>

void main()
{
	int input = 0;
	int i = 0;
	int c = 0;

	fputs("please input a char: ", stdout);
	input = fgetc(stdin);

	FILE* fp = fopen("./data.txt", "r");
	if (fp == NULL)
	{
		fputs("can not open file data.txt\n", stdout);
		return;
	}

	while ((c = fgetc(fp)) != EOF)
	{
		if (c == input)
			i++;
	}

	fprintf(stdout, "there is %d in data.txt\n", i);

	fclose(fp);
}


