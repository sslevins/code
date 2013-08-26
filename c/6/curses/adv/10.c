#include <curses.h>

void main()
{
	initscr();

	WINDOW* win = NULL;

	win = subwin(stdscr, 5, 10, 2, 2);

	int y = 0;
	int x = 0;
	for (y = 0; y < LINES; y++)
		for (x = 0; x < COLS; x++)
			waddch(stdscr, '+');
	wrefresh(stdscr);

	wclear(win);
	int i = 20;
	while (i--)
		waddch(win, '%');
	
	wrefresh(win);

	delwin(win);

	touchwin(stdscr);
	wrefresh(stdscr);


	getch();

	endwin();
}


