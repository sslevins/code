#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

int main()
{
	int ret = 0;

	int sock_id = socket(AF_INET, SOCK_STREAM, 0);
	if (sock_id == -1) {
		printf("socket error\n");
		exit(1);
	}

	struct sockaddr_in addr_in;
	memset(&addr_in, 0, sizeof(addr_in));
	addr_in.sin_family = AF_INET;
	addr_in.sin_port = htons(9527);
	addr_in.sin_addr.s_addr = htonl(INADDR_ANY);
	//inet_addr("127.0.0.1");
	if (addr_in.sin_addr.s_addr == INADDR_NONE)
	{
		printf("bad addr\n");
		exit(1);
	}

	ret = bind(sock_id, 
			(struct sockaddr *)&addr_in, 
			sizeof(addr_in));
	if (ret == -1)
	{
		printf("bind error!\n");
		exit(1);
	}

	ret = listen(sock_id, 1);
	if (ret == -1)
	{
		perror("listen");
		exit(1);
	}

	printf("listenning ...\n");
	struct sockaddr_in cli_addr;
	int len;
	int cli_sockid = accept(sock_id, 
					(struct sockaddr *)&cli_addr, 
					&len);
	//int cli_sockid = accept(sock_id, NULL, NULL);
	if (cli_sockid != -1)
		printf("someone conneting me\n");
	else
		perror("accept");

	printf("port: %hu\n", ntohs(cli_addr.sin_port));
	printf("ip: %s\n", inet_ntoa(cli_addr.sin_addr));
	
	sleep(1);

	char buf[32];
	ret = read(cli_sockid, buf, 32);
	buf[ret] = '\0';
	printf("%s\n", buf);

	close(cli_sockid);
	close(sock_id);
}








