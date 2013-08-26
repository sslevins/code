#include <curses.h>

void main()
{
	initscr();

	printw("please input a char: ");
	int c = getch();

	move(1, 0);

	printw("you just input %c", c);
	refresh();
	sleep(3);

	char buf[128] = {0};

	move(2, 0);
	printw("please input a string: ");
	//getstr(buf);
	getnstr(buf, 3);

	printw("%s", buf);
	refresh();
	sleep(3);

	

	endwin();
}



