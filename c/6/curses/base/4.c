#include <curses.h>

void main()
{
	initscr();

	printw("xxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	printw("xxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	printw("xxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	printw("xxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	printw("xxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	printw("xxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	printw("xxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	printw("xxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	printw("xxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	printw("xxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	printw("xxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	refresh();
	sleep(3);

	move(0, 5);
	refresh();
	sleep(3);

	clrtoeol();
	refresh();
	sleep(3);

	move(2, 2);
	refresh();
	sleep(3);

	clrtobot();
	refresh();
	sleep(3);


	endwin();
}
