#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define STR "hello world!"

static void bail(const char *on_what) {
    fputs(strerror(errno),stderr);
    fputs(": ",stderr);
    fputs(on_what,stderr);
    fputc('\n',stderr);
    exit(1);
}

int main(int argc,char **argv) 
{
	int ret = 0;
	int len = 0;
	char * p = NULL;
	char buf[128];
	bzero(buf, 128);

	int sock_cli = 0;
	int sock_srv = 0;

	FILE * rf = NULL;
	FILE * wf = NULL;

    sock_cli = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( sock_cli == -1 )
        bail("socket()");
	

	struct sockaddr_in addr_cli;
	bzero(&addr_cli, sizeof(addr_cli));
	addr_cli.sin_family = AF_INET;
	addr_cli.sin_port = 0;
	addr_cli.sin_addr.s_addr = INADDR_ANY;
	if (addr_cli.sin_addr.s_addr == INADDR_NONE)
		bail("bad addr");
	ret = bind(sock_cli,
				(struct sockaddr *)&addr_cli,
				sizeof(addr_cli));
	if (ret == -1)
		bail("bind()");

	struct sockaddr_in addr_srv;
	bzero(&addr_srv, sizeof(addr_srv));

	addr_srv.sin_family = AF_INET;
	addr_srv.sin_port = htons(9527);
	addr_srv.sin_addr.s_addr = inet_addr("127.0.0.1");

	len = sizeof(addr_srv);
	ret = connect(sock_cli, 
			(struct sockaddr *)&addr_srv, 
			len);
	if (ret == -1)
		bail("connect()");

	wf = fdopen(sock_cli, "w");
	if (wf == NULL)
		bail("fdopen wf");

	rf = fdopen(dup(sock_cli), "r");
	if (rf == NULL)
		bail("fdopen rf");

	ret = fputs(STR, wf);
	if (ret == -1)
		bail("fputs()");

	fflush(wf);
	shutdown(fileno(wf), SHUT_WR);
	
	fgets(buf, 128, rf);
	shutdown(fileno(rf), SHUT_RD);

	printf("%s\n", buf);

	close(sock_cli);

    return 0;
}




