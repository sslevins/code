#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>

#define oops(m) {perror(m); exit(1);}
#define event_size sizeof(struct input_event)

void move_mouse(int, int, int);

int main()
{
	char * mouse_file = "/dev/input/event3";

	int fd = open(mouse_file, O_RDWR);
	if (fd == -1)
		oops("open mouse_file");
	

	int i = 0;
	while (1)
	{
		move_mouse(i*10, i*10, fd);
		i++;
		sleep(1);
	}
	
	return 0;
}

void __write_event(int type, int code, int value, int fd)
{
	struct input_event event;

	event.type = type;
	event.code = code;
	event.value = value;

	int num = write(fd, &event, sizeof(struct input_event));
	if (num != sizeof(struct input_event))
		perror("move_x");

}

void move_mouse(int x, int y, int fd)
{
	int num = 0;

	__write_event(EV_REL, REL_X, x, fd);
	__write_event(EV_REL, REL_Y, y, fd);
	__write_event(EV_SYN, 0, 0, fd);
}






