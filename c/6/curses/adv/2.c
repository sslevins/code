#include <curses.h>

void main()
{
	int x = 0;
	int y = 0;

	initscr();

	for (y = 0; y < LINES; y++)
	{
		for (x = 0; x < COLS; x++)
		{
			move(y, x);
			addch('*');
		}
	}

	refresh();

	WINDOW* win = newwin(10, 10, 4, 4);
	wclear(win);
	wrefresh(win);

	box(win, '|', '-');
	wrefresh(win);
	getch();

	//refresh();
	touchwin(stdscr);
	wrefresh(stdscr);
	getch();

	endwin();
}



