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

void * do_thread(void *);

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
	// int sock_cli = 0;

	struct sockaddr_in addr_srv;
	struct sockaddr_in addr_cli;
	bzero(&addr_srv, sizeof(addr_srv));
	bzero(&addr_cli, sizeof(addr_cli));

	FILE * rf = NULL;
	FILE * wf = NULL;
	FILE * pf = NULL;

	addr_srv.sin_family = AF_INET;
	addr_srv.sin_port = htons(1234);
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
		int sock_cli = accept(sock_srv, 
					(struct sockaddr *)&addr_cli,
					&len);
		if (sock_cli == -1)
			bail("accept()");
		printf("accepted one connection\n");

		pthread_t t;
		ret = pthread_create(&t, 
								NULL, 
								do_thread, 
								(void *)&sock_cli);
		if (ret != 0)
			bail("pthread_create()");
    }

    return 0;
}

void * do_thread(void * p_sock_cli)
{
	int ret;
	char * p;
	char buf[128];
	bzero(buf, 128);

	pthread_detach(pthread_self());

	FILE * rf = fdopen(*((int *)p_sock_cli), "r");
	FILE * wf = fdopen(dup(*((int *)p_sock_cli)), "w");

	p = fgets(buf, 128, rf);
	if (p == NULL && ferror(rf) != 0)
		bail("fgets()");
	
	shutdown(*(int*)p_sock_cli, SHUT_RD);
	
	int c;
	FILE * pf = popen(buf, "r");
	while ((c = fgetc(pf)) != EOF)
		fputc(c, wf);

	fflush(wf);
	shutdown(*(int*)p_sock_cli, SHUT_WR);

	close(*(int*)p_sock_cli);
}








