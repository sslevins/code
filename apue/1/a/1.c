#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// int fd = creat("1.txt", 0755);
	// int fd = creat("1.txt", S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH);
	int fd = creat("1.txt", 00700|00040|00010|00004|00001);
	if (fd == -1)
	{
		printf("create error\n");
		exit(1);
	}

	return 0;
}
