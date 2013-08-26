#include <curses.h>

void main()
{
	initscr();

	printw("hello world\n");
	printw("goodbye\n");
	refresh();
	sleep(3);

	clear();
	refresh();
	sleep(3);

	printw("goodbye\n");
	refresh();
	sleep(3);
	printw("hello world\n");
	refresh();
	sleep(3);



	endwin();
}
