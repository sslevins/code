#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int fd = open("./hello", O_RDWR|O_TRUNC);
	if (fd == -1) {
		printf("open error\n");
		exit(1);
	}

	dup2(fd, 1);

	FILE * pfile = popen("pwd", "r");

	char buf[128];
	memset(buf, 0, 128);

	fread(buf, 1, 128, pfile);

	fwrite(buf, 1, 128, stdout);

	pclose(pfile);

	return 0;
}


