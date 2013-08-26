#include <stdio.h>

void main()
{
	char buf[128] = {0};
	
	//fgets(buf, 128, stdin);
	gets(buf);

	fputs(buf, stdout);
	//puts(buf);

	//printf("%s", buf);
}

