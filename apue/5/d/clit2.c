#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <errno.h>
#include <signal.h>

#define oops(m, x) {perror(m); exit(x);}

#define CAN_READ 0
#define CAN_WRITE 1

void do_int(int signum)
{
	printf("I have waiting over 3 secs\n");

	printf("producer is killed, I am going to exit\n");

	exit(1);
}

void wait_read(int _semid)
{
	struct sembuf ops[1];
	ops[0].sem_num = CAN_READ;
	ops[0].sem_op = 0;
	ops[0].sem_flg = SEM_UNDO;
	
	semop(_semid, ops, 1);

}

void set_sem(int _semid)
{
	struct sembuf ops[2];

	// can not read again
	ops[0].sem_num = CAN_READ;
	ops[0].sem_op = +1;
	ops[0].sem_flg = SEM_UNDO;

	// can write
	ops[1].sem_num = CAN_WRITE;
	ops[1].sem_op = -1;
	ops[1].sem_flg = SEM_UNDO;
	
	semop(_semid, ops, 2);
}

int main()
{
	int semid = semget(1234, 1, 0666|IPC_CREAT);
	if (semid == -1)
		oops("semget", 1);
	
	int shmid = shmget(9527, 1, 0666|IPC_CREAT);
	if (shmid == -1)
		oops("shmget", 2);

	char * addr = shmat(shmid, NULL, 0);
	if (addr == (char *)-1)
		oops("shmat", 2);
	
	signal(SIGALRM, do_int);

	int i = 0;
	char buf;
	for (i = 0; i < 48; i++)
	{
		alarm(3);
		wait_read(semid);

		strncpy(&buf, addr, 1);

		set_sem(semid);

		printf("c:%c\n", buf);

		sleep(1);
	}

	if (shmdt(addr) == -1)
		oops("shmdt", 3);
}



