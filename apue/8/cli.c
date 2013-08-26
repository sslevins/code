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

	//int sock_id = socket(AF_INET, SOCK_STREAM, IPPORTOL_TCP);
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

	ret = getsockname(sock_id, &addr, &len);
	if (ret == -1)
	{
		printf("getsockname error! ");
		exit(1);
	}

	struct sockaddr_in temp_in;
	memcpy(&temp_in, &addr, sizeof(temp_in));

	struct in_addr temp = temp_in.sin_addr;
	in_addr_t n_addr = inet_lnaof(temp);
	printf("my host_addr: %d\n", n_addr);

	in_addr_t h_addr = inet_netof(temp);
	printf("my net_addr: %x\n", h_addr);


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

	// close(sock_id);

	//system("netstat -pa --tcp | grep 'a.out'");

	write(sock_id, "hello world!", 13);
}








