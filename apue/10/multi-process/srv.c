#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


#define STR "hello"

static void bail(const char *on_what) {
    fputs(strerror(errno),stderr);
    fputs(": ",stderr);
    fputs(on_what,stderr);
    fputc('\n',stderr);
    exit(1);
}

int main(int argc,char **argv) 
{
	int len = 0;
	int ret = 0;
	int pid = 0;
	char * p = NULL;
	char buf[128];
	bzero(buf, 128);

	int sock_srv = 0;
	int sock_cli = 0;

	struct sockaddr_in addr_srv;
	struct sockaddr_in addr_cli;
	bzero(&addr_srv, sizeof(addr_srv));
	bzero(&addr_cli, sizeof(addr_cli));

	FILE * rf = NULL;
	FILE * wf = NULL;

	addr_srv.sin_family = AF_INET;
	addr_srv.sin_port = htons(9527);
	addr_srv.sin_addr.s_addr = inet_addr("127.0.0.1");

	sock_srv = socket(AF_INET, SOCK_STREAM, 0);
	if (sock_srv == -1)
		bail("socket()");

    ret = bind(sock_srv, 
				(struct sockaddr *)&addr_srv, 
				sizeof(addr_srv));
    if ( ret == -1 )
        bail("bind()");
	
	ret = listen(sock_srv, 5);
	if (ret == -1)
		bail("listen()");

    for (;;) {
		printf("accepting ...\n");
		sock_cli = accept(sock_srv, 
					(struct sockaddr *)&addr_cli,
					&len);
		if (sock_cli == -1)
			bail("accept()");
		printf("accepted one connection\n");

		rf = fdopen(sock_cli, "r");
		wf = fdopen(dup(sock_cli), "w");

		pid = fork();	
		if (pid == -1)			// error
			bail("fork()");
		else if (pid > 0) {		// parent
			close(sock_cli);
			continue;
		}

		// child
		p = fgets(buf, 128, rf);
		if (p == NULL)
			break;
		shutdown(fileno(rf), SHUT_RD);
		printf("server rcv: %s\n", buf);

		printf("wait\n");

		ret = fputs(buf, wf);
		if (ret == -1)
			bail("fputs()");
		fflush(wf);
		shutdown(sock_cli, SHUT_WR);

		close(sock_cli);
    }

    return 0;
}






