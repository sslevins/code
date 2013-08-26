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
	addr_in.sin_port = 0;
	addr_in.sin_addr.s_addr = INADDR_ANY;

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

	struct sockaddr addr;
	memset(&addr, 0, sizeof(addr));
	int len;

	// step 3
	struct sockaddr_in other_addr;
	memset(&other_addr, 0, sizeof(other_addr));

	other_addr.sin_family = AF_INET;
	other_addr.sin_port = htons(9527);
	other_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = connect(sock_id, 
		(struct sockaddr *)&other_addr,
		sizeof(struct sockaddr));
	if (ret != 0)
	{
		perror("connect");
		exit(1);
	}
	else if (ret == 0)
	{
		printf("connect success\n");
	}


	char buf[128];
	bzero(buf, 128);

	write(sock_id, "a", 1);
	write(sock_id, "b", 1);
	write(sock_id, "c", 1);
	write(sock_id, "d", 1);

	// close(sock_id);
	shutdown(sock_id, SHUT_WR);

	ret = read(sock_id, buf, sizeof(buf));
	if (ret == -1) {
		perror("read");
		exit(1);
	} 
	else if (ret == 0) {
		printf("read eof\n");
	}
		
	write(1, buf, ret);
	fputc('\n', stdout);

	close(sock_id);
}








