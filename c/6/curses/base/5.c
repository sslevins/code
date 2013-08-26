#include <curses.h>

void main()
{
	initscr();

	printw("hello world\n");
	refresh();
	sleep(3);

	//attron(A_REVERSE);
	//attron(A_BOLD);
	//attron(A_UNDERLINE);
	attron(A_STANDOUT);

	printw("hello world\n");
	refresh();
	sleep(3);

	attroff(A_STANDOUT);

	printw("hello world\n");
	refresh();
	sleep(3);

	//attron(A_REVERSE);
	//attron(A_BOLD);
	//attron(A_UNDERLINE);
	attrset(A_REVERSE|A_BOLD|A_UNDERLINE);

	printw("goodbye\n");
	refresh();
	sleep(3);

	standout();	// attron(A_STANDOUT);
	printw("goodbye\n");
	refresh();
	sleep(3);
	standend(); // attroff(A_STANDOUT);

	printw("goodbye");
	refresh();
	sleep(3);

	endwin();
}
