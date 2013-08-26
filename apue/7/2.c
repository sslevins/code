#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>

#define oops(m) {perror(m); exit(1);}
#define event_size sizeof(struct input_event)

int main()
{
	char * keypad_file = "/dev/input/event4";

	int fd = open(keypad_file, O_RDWR);
	if (fd == -1)
		oops("open keypad_file");
	
	struct input_event event;


	struct input_event arr[6];
	read(fd, arr, event_size*3);

	int num = 0;
	while (1)
	{
		sleep(1);
		num = read(fd, arr, event_size*6);
		if(num != event_size*6)
			oops("read keypad_file");

		arr[1].code += 1;
		arr[4].code += 1;

		num = write(fd, arr, event_size*6);
		if (num != event_size*6)
			oops("write keypad_file");

/*
		printf("[%ld %ld] %hu %hu %d\n", 
					event.time.tv_sec,
					event.time.tv_usec,
					event.type,
					event.code,
					event.value);
*/
	}
	
	return 0;
}



