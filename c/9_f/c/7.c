#include <stdio.h>

void main()
{
	char buf_w[128] = "hello wolrd";
	char buf_r[128] = {0};

	FILE* fp = fopen("./data.txt", "w+");

	fwrite(buf_w, 11, 1, fp);

	fseek(fp, 0, SEEK_SET);

	fread(buf_r, 11, 1, fp);

	printf("%s\n", buf_r);

	fclose(fp);
}


