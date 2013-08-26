#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#define STR "hello"

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
		addr_in.sin_port = htons(1234);
		addr_in.sin_addr.s_addr = inet_addr("127.0.0.1");

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
		if (cli_sockid != -1)
			printf("someone conneting me\n");
		else
			perror("accept");

		FILE * rx = fdopen(cli_sockid, "r");
		FILE * wx = fdopen(dup(cli_sockid), "w");

		setlinebuf(rx);
		setlinebuf(wx);

		char buf[32];
		while (1)
		{
			bzero(buf, 32);

			char * p = fgets(buf, 32, rx);
			if (p == NULL)
				break;

			printf("%s\n", buf);

		}
		printf("client send meg over\n");

		write(cli_sockid, STR, sizeof(STR));

		shutdown(cli_sockid, SHUT_WR);

		close(cli_sockid);
		close(sock_id);
}








