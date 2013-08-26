#include <curses.h>

void main()
{
	initscr();

	WINDOW* win = newwin(16, 24, 5, 5);
	wrefresh(win);

	int i = 10;
	while (i--)
	{
		//addch('*');
		mvaddch(i, 0, '*');
		refresh();
		sleep(1);

		//waddch(win, '+');
		mvwaddch(win, i, 0, '+');
		wrefresh(win);
		sleep(1);
	}

	getch();

	endwin();
}
