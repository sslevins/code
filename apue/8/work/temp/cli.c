#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#define STR "hello world!"

int main()
{
	int ret = 0;

	// step 1
	int sock_id = socket(AF_INET, 
					SOCK_STREAM, 
					IPPROTO_TCP);
	if (sock_id == -1) {
		perror("socket");
		exit(1);
	}

	// step 2 *
	struct sockaddr_in cli_addr;
	bzero(&cli_addr, sizeof(cli_addr));
	cli_addr.sin_family = AF_INET;
	cli_addr.sin_port = 0;//htons(9090);
	cli_addr.sin_addr.s_addr = INADDR_ANY;//inet_addr("127.0.0.1");
	if (cli_addr.sin_addr.s_addr == INADDR_NONE) {
		printf("bad address\n");
		exit(1);
	}

	ret = bind(sock_id, 
				(struct sockaddr *)&cli_addr, 
				sizeof(cli_addr));
	if (ret == -1) {
		printf("bind error\n");
		exit(1);
	}


	// step 3
	struct sockaddr_in srv_addr;
	bzero(&srv_addr, sizeof(srv_addr));
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_port = htons(9528);
	srv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (srv_addr.sin_addr.s_addr == INADDR_NONE) {
		printf("bad address\n");
		exit(1);
	}

	ret = connect(sock_id, 
					(struct sockaddr *)&srv_addr,
					sizeof(srv_addr));
	if (ret == -1) {
		perror("connect");
		exit(1);
	}

	FILE* rf = fdopen(sock_id, "r");
	FILE* wf = fdopen(dup(sock_id), "w");

	int sock_rid = dup(sock_id);

	int c = 0;
	char buf[128];

	fd_set rset;
	struct timeval tv = {10, 0};

	while (1)
	{
		ret = (int)fgets(buf, 128, stdin);
		if (ret == (int)NULL) {
			printf("fgets errot\n");
			close(sock_id);
			exit(1);
		}

		// step 4
		ret = write(sock_id, buf, strlen(buf)+1);
		if (ret == -1)
		{
			perror("send");
			exit(1);
		}

		if (strncasecmp(buf, "quit", 4) == 0)
			break;

		ret = select(sock_rid+1, 
						&rset, NULL, NULL, &tv); 
		if (ret == -1) {
			perror("select");
			exit(1);
		}
		else if (ret)
			printf("sock_rid hava data\n");
	  	else
	   		printf("timeout\n");


		ret = read(sock_rid, buf, 128);
		if (ret == -1) {
			perror("read");
			exit(1);
		} 

		write(1, buf, ret);
	}
	

	sleep(1);
	// step 5
	close(sock_id);

	return 0;
}





