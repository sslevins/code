#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int fd = 2;

	char buf[128] = "hello world!\n";

	int ret = write(fd, buf, 128);
	if (ret != 128)
	{
		perror("write");
		exit(1);
	}

	memset(buf, 0, 128);
	fd = 0;
	ret = read(fd, buf, 128);
	if (ret == -1)
	{
		perror("read");
		exit(2);
	}

	printf("%s\n", buf);
}




