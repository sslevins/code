#include <stdio.h>

void main()
{
	FILE* fp = fopen("./data.txt", "r");

	int c = 0;
	while ((c = fgetc(fp)) != EOF)
		;
	
	if (feof(fp))
		printf("there is end of file\n");
	else if (ferror(fp))
		printf("there is some error\n");
	else
		printf("other\n");
}

