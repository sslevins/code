#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int fd = open("./b.txt", 
					O_RDONLY | O_CREAT,
					0755);
	if (fd == -1)
	{
		printf("open error\n");
		exit(1);
	}

	printf("open success\n");

	char buf[128];
	memset(buf, 0, 128);

	int ret = read(fd, buf, 128);
	if (ret == -1)
	{
		printf("read error\n");
		exit(2);
	}

	printf("%s", buf);

	close(fd);

	return 0;
}


