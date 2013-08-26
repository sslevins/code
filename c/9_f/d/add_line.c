#include <stdio.h>

void main()
{
	FILE* cd_fp = fopen("./cd.db", "a+");
	
	char* catalog = "001";
	char* name = "hello";
	char* type = "jazz";
	char* artist = "tom";

	fprintf(cd_fp, 
			"%s:%s:%s:%s\n", 
			catalog, name, type, artist); 

	fclose(cd_fp);
}
