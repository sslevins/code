#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main()
{
	DIR * dir = opendir("/home/uplooking");
	if (dir == NULL)
	{
		printf("opendir error!\n");
		exit(1);
	}

	struct dirent * cur = readdir(dir);

	struct stat st;
	int ret = stat("/home/uplooking", &st);
	if (ret == -1)
	{
		printf("stat error!\n");
		exit(2);
	}

	printf("%d\n", st.st_size);


	closedir(dir);

	return 0;
}

