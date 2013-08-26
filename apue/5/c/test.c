#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <errno.h>

#define oops(m, x) {perror(m); exit(x);}

int main()
{
	int msqid = msgget(1234, 0666|IPC_CREAT);
	if (msqid == -1)
		oops("msgget", 1);
	
	if (shmctl(msqid, IPC_RMID, NULL) == -1)
		oops("shmctl", 2);
}



