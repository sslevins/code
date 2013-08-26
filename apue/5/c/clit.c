#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>

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
		oops("msgget", 3);
	
	struct msgbuf read_over = {2, "read over"};
	struct msgbuf read_end = {2, "read end"};
	struct msgbuf write_buf;
	memset(&write_buf, 0, sizeof(write_buf));

	int shmid = shmget(9527, 1, 0666|IPC_CREAT);
	if (shmid == -1)
	{
		printf("shmget error!\n");
		exit(1);
	}


	char * addr = shmat(shmid, NULL, 0);
	if (addr == (void *)-1)
	{
		printf("shmat error!\n");
		exit(2);
	}

	char buf;
	int ret;
	while (1)
	{
		ret = msgrcv(msqid, &write_buf, 32, 1, 0);
		if (ret == -1)
			oops("msgrcv", 1);

		if (strcmp(write_buf.mtext, "write end") 
				== 0)
			break;
		else if (strcmp(write_buf.mtext, "write over") 
				== 0)
		{
			strncpy(&buf, addr, 1);
			printf("%c", buf);
			fflush(stdout);
			
			msgsnd(msqid, &read_over, 32, 0);
		}
	}

	shmdt(addr);
}



