#include <stdio.h>
#include <string.h>

void main()
{
	FILE* fp = fopen("./cd.db", "r");
	FILE* temp = fopen("./temp.db", "a+");

	char buf[128] = {0};
	int c = 0;
	int i = 0;

	while (1)
	{
		c = fgetc(fp);

		if (c == EOF)
			break;

		if (c != '\n')
		{
			buf[i] = c;
			i++;
		}
		else 	// c == '\n'
		{
			buf[i] = '\0';
			i = 0;

			char * p = strstr(buf, "blue");
			if (p != NULL)
				printf("%s\n", buf);
			else
				fprintf(temp, "%s\n", buf);

			memset(buf, 0, 128);
		}
	}

	remove("./cd.db");
	rename("temp.db", "cd.db");
}



