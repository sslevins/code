#include <curses.h>

void main()
{
	int y = 0;
	int x = 0;

	initscr();

	for (y = 0; y < LINES; y++)
		for (x = 0; x < COLS; x++)
			waddch(stdscr, '+');
	refresh();
	sleep(2);
	

	WINDOW* pad = NULL;
	pad = newpad(100, 100);
	for (y = 0; y < 100; y++)
		for (x = 0; x < 100; x++)
			waddch(pad, '%');
	
	prefresh(pad, 10, 10, 4, 4, 10, 10);

	sleep(3);

	endwin();
}
