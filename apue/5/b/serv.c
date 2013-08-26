#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

#define oops(m, x) {perror(m); exit(x);}

struct msgbuf
{
	long mtype;
	char mtext[32];
};

int main()
{
	int msqid = msgget(1234, 0666|IPC_CREAT);
	if (msqid == -1)
		oops("msgget", 1);

	struct msgbuf buf = {10, "hello world!"};
	
	msgsnd(msqid, &buf, 32, 0);

	sleep(10);

}






