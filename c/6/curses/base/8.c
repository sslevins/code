#include <curses.h>

void main()
{
	initscr();

	printw("please input a char: ");
	nocbreak();
	int c = getch();

	move(1, 0);
	printw("you just input '%c'", c);
	refresh();

	sleep(30);

	endwin();
}
