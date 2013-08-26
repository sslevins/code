#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int ret = 0;

	// step 1
	int srv_id = socket(AF_INET, 
							SOCK_STREAM, 
							IPPROTO_TCP);
	if (srv_id == -1) {
		perror("socket");
		exit(1);
	}

	// step 2
	struct sockaddr_in srv_addr;
	bzero(&srv_addr, sizeof(srv_addr));
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_port = htons(9528);
	srv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (srv_addr.sin_addr.s_addr == INADDR_NONE) {
		printf("bad address.");
		exit(1);
	}

	ret = bind(srv_id, 
				(struct sockaddr *)&srv_addr, 
				sizeof(srv_addr));
	if (ret == -1) {
		perror("bind");
		exit(1);
	}

	// step 3
	ret = listen(srv_id, 3);
	if (ret == -1) {
		perror("listen");
		exit(1);
	}

	// step 4
	struct sockaddr_in cli_addr;
	int len = 0;
	char buf[128];
	int cli_id = 0;

	// step 5
	bzero(&cli_addr, sizeof(cli_addr));
	cli_id = accept(srv_id, (struct sockaddr *)&cli_addr, &len);
	if (cli_id == -1) {
		perror("accept");
		exit(1);
	}

	int cli_wid = dup(cli_id);

	FILE* p = NULL;
	int c = 0;

/*
	long flag = fcntl(cli_id, F_GETFL);
	fcntl(cli_id, F_SETFL, flag|O_NONBLOCK);
*/

	fd_set rset;

	struct timeval tv = {10, 0};

	while (1)
	{
		bzero(buf, 128);
		ret = select(cli_id+1, 
						&rset, NULL, NULL, &tv);
		if (ret == -1)
			perror("select");
		else if (ret)
			printf("cli_id hava data\n");
		else
			printf("timeout\n");

		ret = read(cli_id, buf, 128);
		if (ret == -1) {
			printf("fread error");
			exit(1);
		} 

		if (strncasecmp(buf, "quit", 4) == 0)
			break;

		write(cli_wid, "world", 6);
		printf("write world over\n");
	}

	// step 6
	close(cli_id);
	close(srv_id);

	return 0;
}

