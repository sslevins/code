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

#ifndef TRUE
#define TRUE    1
#define FALSE   0
#endif

static void bail(const char *on_what) {
    fputs(strerror(errno),stderr);
    fputs(": ",stderr);
    fputs(on_what,stderr);
    fputc('\n',stderr);
    exit(1);
}

int main(int argc,char **argv) {
    int z;
    socklen_t x;
    struct sockaddr_in adr;
    int len_inet;         
    int s;               
    char dgram[512];    

    s = socket(AF_INET,SOCK_DGRAM,0);
    if ( s == -1 )
        bail("socket()");

    len_inet = sizeof(adr);
/*
	bzero(&adr, sizeof(adr));
	adr.sin_family = AF_INET;
	adr.sin_port = htons(1234);
	adr.sin_addr.s_addr = inet_addr("192.168.1.255");

    z = bind(s,
        (struct sockaddr *)&adr,
        len_inet);

    if ( z == -1 )
        bail("bind(2)");
	*/

    for (;;) {
        z = recv(s, dgram, sizeof(dgram), 0);

        if ( z < 0 )
            bail("recv()"); 

        fwrite(dgram,z,1,stdout);
        putchar('\n');

        fflush(stdout);
    }

    return 0;
}
