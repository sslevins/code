#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>

#define oops(m) {perror(m); exit(1);}

int main()
{
	char * keypad_file = "/dev/input/event4";

	int fd = open(keypad_file, O_RDONLY);
	if (fd == -1)
		oops("open keypad_file");
	
	struct input_event event;

	int rnum = 0;
	while (1)
	{
		rnum = read(fd, &event, sizeof(event));
		if(rnum != sizeof(event))
			oops("read keypad_file");

		printf("[%ld %ld] %hu %hu %d\n", 
					event.time.tv_sec,
					event.time.tv_usec,
					event.type,
					event.code,
					event.value);
	}
	
	return 0;
}



