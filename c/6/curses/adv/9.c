#include <curses.h>

void main()
{
	initscr();

	WINDOW* win = NULL;
	win = newwin(10, 10, 4, 4);

	int y = 0;
	int x = 0;
	for (y = 0; y < LINES; y++)
		for (x = 0; x < COLS; x++)
			addch('+');
	wrefresh(stdscr);

	scrollok(win, TRUE);

	while (1)
	{
		wprintw(win, "hello world");
		wrefresh(win);
		sleep(1);
	}


	endwin();
}
