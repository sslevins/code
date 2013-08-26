#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

// SO_RCVBUF, SO_SNDBUF, SO_TYPE

int main()
{
	//int sockid = socket(AF_INET, SOCK_STREAM, 0);
	int sockid = socket(AF_INET, SOCK_DGRAM, 0);

	int recvbuf = 0;
	int len = sizeof(recvbuf);
	int ret = getsockopt(sockid, SOL_SOCKET, 
							SO_RCVBUF, &recvbuf, &len);
	printf("rcvbuf: %d\n", recvbuf);

	int sendbuf = 0;
	ret = getsockopt(sockid, SOL_SOCKET, 
							SO_SNDBUF, &sendbuf, &len);
	printf("sndbuf: %d\n", sendbuf);

	recvbuf = 65535;
	len = sizeof(recvbuf);
	setsockopt(sockid, SOL_SOCKET, SO_RCVBUF, 
				&recvbuf, len);

	sendbuf = 65535;
	len = sizeof(sendbuf);
	setsockopt(sockid, SOL_SOCKET, SO_RCVBUF, 
				&sendbuf, len);
	printf("new rcvbuf: %d\n", recvbuf);
	printf("new sndbuf: %d\n", sendbuf);

	int type = 0;
	len = sizeof(type);
	getsockopt(sockid, SOL_SOCKET, SO_TYPE, 
				&type, &len);
	if (type == SOCK_STREAM)
		printf("using tcp\n");
	else if (type == SOCK_DGRAM)
		printf("using udp\n");
	else
		printf("other\n");
}












