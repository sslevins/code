#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

void __print_parent()
{
	DIR * dir = opendir("./");
	DIR * parent = opendir("../");

	struct dirent * cur = NULL;

	struct stat prnt;
	struct stat buf;
	stat(".", &buf);
	stat("..", &prnt);

	if (buf.st_ino == prnt.st_ino)
	{
		//printf("/");
		return ;
	}

	chdir("..");
	__print_parent();
	
	while ((cur = readdir(parent)) != NULL )
	{
		if (cur->d_ino == buf.st_ino)
			printf("/%s", cur->d_name);
	}
}

void print_parent()
{
	__print_parent();
	printf("\n");
}

int main()
{
	print_parent();

	return 0;
}

