#include <stdio.h>

void main()
{
	FILE* fp = fopen("./data.txt", "r+");

	fseek(fp, -1L, SEEK_END);
	//SEEK_CUR, SEEK_SET, SET_END

	fputc('x', fp);

}
