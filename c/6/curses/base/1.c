#include <curses.h>

void main()
{
	initscr();

	addch('a');
	refresh();
	sleep(2);

/*
	chtype buf[] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '\n', '\0'};
	addchstr(buf);
	refresh();
	sleep(2);
	*/

	printw("%s", "hello world\n");
	refresh();
	sleep(2);

	endwin();
}
