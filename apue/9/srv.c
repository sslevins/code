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

	int srv_id = socket(AF_INET, SOCK_DGRAM, 0);
	if (srv_id == -1) {
		perror("socket");
		goto socket_error;
	}

	struct sockaddr_in srv_addr;
	bzero(&srv_addr, sizeof(srv_addr));
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_port = htons(9527);
	srv_addr.sin_addr.s_addr = inet_addr("192.168.1.110");
	ret = bind(srv_id, (struct sockaddr *)&srv_addr, sizeof(srv_addr));
	if (ret == -1) {
		perror("bind");
		goto bind_error;
	}

	struct sockaddr_in cli_addr;
	bzero(&cli_addr, sizeof(cli_addr));

	char buf[128];
	int len = 0;
	while (1)
	{
		ret = recvfrom(srv_id, buf, 128, 0, 
					(struct sockaddr *)&cli_addr, 
					&len);
		if (ret == -1)
		{
			printf("recvfrom error\n");
			goto recvfrom_error;
		}
		write(1, buf, ret);
		putc('\n', stdout);

		printf("rcvfrom: %s %u\n", 
				inet_ntoa(cli_addr.sin_addr), 
				ntohs(cli_addr.sin_port));
	}

	close(srv_id);

	return 0;

recvfrom_error:
bind_error:
	close(srv_id);
socket_error:
	exit(1);
}





