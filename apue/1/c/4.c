#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include <errno.h>

int main()
{
	char buf[128];
	memset(buf, 0, 128);

	int max_fd = 0;

	int fd_1 = open("./x.txt", O_RDWR);
	max_fd = max_fd > fd_1 ? max_fd : fd_1;

	int fd_2 = open("./y.txt", O_RDWR);
	max_fd = max_fd > fd_2 ? max_fd : fd_2;

	int fd_3 = open("./z.txt", O_RDWR);
	max_fd = max_fd > fd_3 ? max_fd : fd_3;

	struct timeval time;
	time.tv_sec = 3;
	time.tv_usec = 500000;

	fd_set r_set;
	fd_set w_set;
	fd_set e_set;

	FD_ZERO(&r_set);
	FD_ZERO(&w_set);
	FD_ZERO(&e_set);

	FD_SET(0, &r_set);
	FD_SET(fd_1, &r_set);
	FD_SET(fd_2, &r_set);
	FD_SET(fd_3, &r_set);

	int ret = select(max_fd+1, &r_set, NULL, NULL, &time);

	if (ret == -1)
	{
		perror("select");
		exit(1);
	} 
	else if (ret == 0)
	{
		printf("no data is inputed.\n");
		exit(2);
	}

	if (FD_ISSET(0, &r_set))
		read(0, buf, 128);
	if (FD_ISSET(fd_1, &r_set))
		read(fd_1, buf, 128);
	if (FD_ISSET(fd_2, &r_set))
		read(fd_2, buf, 128);
	if (FD_ISSET(fd_3, &r_set))
		read(fd_3, buf, 128);
		

	printf("%s", buf);
}





