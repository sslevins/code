#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int ret = 0;
	int fd = 0;
/*
	fd = open("./a.txt", O_RDWR | O_CREAT, 0755);
	if (fd == -1)
	{
		printf("open err\n");
		exit(1);
	}

	char * str = "hello world";

	ret = write(fd, str, strlen(str));
	if (ret == -1)
	{
		printf("write error\n");
		exit(2);
	}
	close(fd);
*/

	fd = open("./a.txt", O_RDWR | O_CREAT, 0755);
	if (fd == -1)
	{
		printf("open err\n");
		exit(1);
	}

	char buf[128];
	memset(buf, 0, 128);

	ret = read(fd, buf, 128);
	if (ret == -1)
	{
		printf("read error\n");
		exit(3);
	}

	printf("%s", buf);

	close(fd);

	return 0;
}







