#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	FILE * pfile = popen("pwd", "r");

	char buf[128];
	memset(buf, 0, 128);

	fread(buf, 1, 128, pfile);

	fwrite(buf, 1, 128, stdout);

	pclose(pfile);

	return 0;
}


