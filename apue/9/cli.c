#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

int main()
{
	int ret = 0;

	int cli_id = socket(AF_INET, SOCK_DGRAM, 0);
	if (cli_id == -1) {
		perror("socket");
		goto exit;
	}

	struct sockaddr_in srv_addr;
	bzero(&srv_addr, sizeof(srv_addr));
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_port = htons(9527);
	srv_addr.sin_addr.s_addr = inet_addr("192.168.1.110");

	char hello[] = "hello world!";
	ret = sendto(cli_id, hello, sizeof(hello), 0, 
					(struct sockaddr *)&srv_addr,
					sizeof(srv_addr));
	if (ret == -1) {
		perror("sendto");
		goto exit;
	}

	printf("send success!\n");

	return 0;

exit:
	close(cli_id);
	exit(1);
}





