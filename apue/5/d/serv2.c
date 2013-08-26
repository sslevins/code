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

int semid = 0;
int shmid = 0;

union semun {
	int val;
	struct semid_ds *buf;
	unsigned short  *array;
	struct seminfo  *__buf;
};

void end_func(int sig_num)
{
	printf("\nYou just input ctl+c, going to exit\n");

	struct sembuf ops[1];
	// can not read
	ops[0].sem_num = CAN_READ;
	ops[0].sem_op = +1;
	ops[0].sem_flg = SEM_UNDO;
	
	semop(semid, ops, 1); 

	sleep(5);
	
	semctl(semid, 0, IPC_RMID);

	shmctl(shmid, IPC_RMID, NULL);

	exit(0);
}

void outtime_func(int signum)
{
	printf("I have waiting over 3 secs\n");
	printf("customer is killed, I am going to exit\n");
	 
	exit(1);

}

void init_sem_val(int _semid, 
					int _semnum, int _data)
{
	union semun u;
	u.val = _data;
	semctl(_semid, _semnum, SETVAL, u);
}

void wait_write(int _semid)
{
	struct sembuf ops[1];
	// wait for write
	ops[0].sem_num = CAN_WRITE;
	ops[0].sem_op = 0;
	ops[0].sem_flg = SEM_UNDO;
	
	semop(_semid, ops, 1); 
}

void set_sem(int _semid)
{
	struct sembuf ops[2];
	
	// can not write again
	ops[0].sem_num = CAN_WRITE;
	ops[0].sem_op = +1;
	ops[0].sem_flg = SEM_UNDO;	

	// can read
	ops[1].sem_num = CAN_READ;
	ops[1].sem_op = -1;
	ops[1].sem_flg = SEM_UNDO;
	
	semop(_semid, ops, 2); 
}

int main()
{
	int ret = 0;
	semid = semget(1234, 1, 0666|IPC_CREAT);
	if (semid != -1)
	{
		ret = semctl(semid, 0, IPC_RMID);
		if (ret == -1) {
			perror("rm semset");
			exit(1);
		}
	}

	semid = semget(1234, 2, 0666|IPC_CREAT|IPC_EXCL);
	if (semid == -1)
		oops("semget", 1);
	
	init_sem_val(semid, CAN_WRITE, 0);
	init_sem_val(semid, CAN_READ, 1);

	shmid = shmget(9527, 1, 0666|IPC_CREAT);
	if (shmid == -1)
		oops("shmget", 2);

	char * addr = shmat(shmid, NULL, 0);
	if (addr == (char *)-1)
		oops("shmat", 2);
	
	signal(SIGINT, end_func);
	signal(SIGALRM, outtime_func);

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
		alarm(3);
		wait_write(semid);

		strcpy(addr, &buf[i]);

		set_sem(semid);

		printf("s:%c\n", buf[i]);
		fflush(stdout);

		sleep(2);
	}

	if (shmdt(addr) == -1)
		oops("shmdt", 3);

	if (shmctl(shmid, IPC_RMID, NULL) == -1)
		oops("shmctl", 4);
	
}



