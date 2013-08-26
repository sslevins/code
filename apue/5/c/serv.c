#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
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
	msgctl(1234, IPC_RMID, NULL);
	shmctl(9527, IPC_RMID, NULL);

	int msqid = msgget(1234, 0666|IPC_CREAT);
	if (msqid == -1)
		oops("msgget", 3);
	
	struct msgbuf write_over = {1, "write over"};
	struct msgbuf write_end = {1, "write end"};
	struct msgbuf read_buf;
	memset(&read_buf, 0, sizeof(read_buf));

	int shmid = shmget(9527, 1, 0666|IPC_CREAT);
	if (shmid == -1)
		oops("shmget", 1);

	char * addr = shmat(shmid, NULL, 0);
	if (addr == (char *)-1)
		oops("shmat", 2);

	char c;
	int i = 0;
	char buf[48];
	for (c = 'a'; c <= 'z'; c++, i++)
		buf[i] = c;
	for (c = 'A'; c <= 'Z'; c++, i++)
		buf[i] = c;

	i = 0;
	for (i = 0; i < 48; i++)
	{
		strcpy(addr, &buf[i]);
		printf("s:%c\n", buf[i]);
		msgsnd(msqid, &write_over, 32, 0);

		msgrcv(msqid, &read_buf, 32, 2, 0);
		if (strcmp(read_buf.mtext, "read over") 
			== 0)
			continue;
		else {
			printf("msgrcv not read over");
			exit(1);
		}
	}

	msgsnd(msqid, &write_end, 32, 0);

	if (shmdt(addr) == -1)
		oops("shmdt", 3);

	//if (shmctl(shmid, IPC_RMID, NULL) == -1)
	//	oops("shmctl", 4);
}



