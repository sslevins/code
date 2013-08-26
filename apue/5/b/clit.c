#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

#define oops(m, x) {perror(m); exit(x);}


int main()
{
	int msqid = msgget(1234, 0666|IPC_CREAT);
	if (msqid == -1)
		oops("msgget", 1);

	struct msgbuf
	{
		long mtype;
		char mtext[32];
	} msg;
	memset(msg.mtext, 0, 32);
	
	msgrcv(msqid, &msg, 32, 1, 0);

	char buf[32];
	memset(buf, 0, 32);

	strcpy(buf, msg.mtext);
	printf("%s\n", buf);
}






