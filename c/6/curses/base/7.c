#include <curses.h>

void main()
{
	char buf[128] = {0};

	initscr();

	noecho();

	printw("please input a string: ");
	getstr(buf);

	move(1, 0);
	printw("you just input \"%s\"\n", buf);
	refresh();
	sleep(3);

	echo();

	endwin();
}

