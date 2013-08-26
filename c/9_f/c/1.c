#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE* fp = fopen("./data.txt", "a");	

	if (fp == NULL) {
		printf("here\n");
		exit(1);
	}

	fputc('y', fp);


	fclose(fp);
}




