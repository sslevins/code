#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#ifndef TRUE
#define TRUE    1
#define FALSE   0
#endif

#define STR "hello"

static void bail(const char *on_what) {
    fputs(strerror(errno),stderr);
    fputs(": ",stderr);
    fputs(on_what,stderr);
    fputc('\n',stderr);
    exit(1);
}

int main(int argc,char **argv) {
    short x;     
    double I0;  
    double I;  
    char bcbuf[512], *bp;
    int z;           
    int s;             
    struct sockaddr_in adr_srvr;
    int len_srvr;               
    struct sockaddr_in adr_bc;  
    int len_bc;                 
    static int so_broadcast = TRUE;

    s = socket(AF_INET,SOCK_DGRAM,0);
    if ( s == -1 )
        bail("socket()");

    z = setsockopt(s, SOL_SOCKET,
        			SO_BROADCAST, &so_broadcast, 
					sizeof(so_broadcast));
    if ( z == -1 )
        bail("setsockopt(SO_BROADCAST)");


/*
	adr_srvr.sin_family = AF_INET;
	adr_srvr.sin_port = htons(9527);
	adr_srvr.sin_addr.s_addr = inet_addr("192.168.1.110");

    z = bind(s, (struct sockaddr *)&adr_srvr, sizeof(adr_srvr));
*/

    if ( z == -1 )
        bail("bind()");

	adr_bc.sin_family = AF_INET;
	adr_bc.sin_port = htons(1234);
	adr_bc.sin_addr.s_addr = inet_addr("192.168.1.255");

    for (;;) {
        z = sendto(s, STR, sizeof(STR), 0,
            	(struct sockaddr *)&adr_bc, sizeof(adr_bc));

        if ( z == -1 )
            bail("sendto()");

        sleep(4);
    }

    return 0;
}
