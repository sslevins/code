#include <curses.h>

void setwin(void)
{
	int y = 0;
	int x = 0;
	for (y = 0; y < LINES; y++)
	{
		for (x = 0; x < COLS; x++)
		{
			move(y, x);
			addch('*');
		}
	}

	refresh();

}

void main()
{
	int x = 0;
	int y = 0;

	initscr();
	setwin();

	WINDOW* win = newwin(4, 4, 0, 0);
	wclear(win);
	wrefresh(win);

	box(win, '|', '-');
	wrefresh(win);

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		mvwin(win, i, i);
		touchwin(win);
		wrefresh(win);
		sleep(1);

		touchwin(stdscr);
		wrefresh(stdscr);
		//sleep(1);
	}

	getch();

	endwin();
}



