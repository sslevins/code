#include <curses.h>

void main()
{
	initscr();

	printw("hello world");
	refresh();
	sleep(3);

	move(0, 3);
	refresh();
	sleep(3);

	insch('x');
	refresh();
	sleep(3);

	delch();
	refresh();
	sleep(3);


	insertln();
	refresh();
	sleep(3);

	deleteln();
	refresh();
	sleep(3);

	endwin();
}
