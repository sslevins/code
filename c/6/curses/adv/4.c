#include <curses.h>

void setwin(WINDOW* win, char c)
{
	int y = 0; 
	int x = 0;

	for (y = 0; y < 8; y++)
	{
		for (x = 0; x < 4; x++)
		{
			wmove(win, y, x);
			waddch(win, c);
		}
	}
}

void main()
{
	int y = 0; 
	int x = 0;

	initscr();

	WINDOW* win1 = newwin(8, 4, 5, 5);
	setwin(win1, '1');

	WINDOW* win2 = newwin(8, 4, 5, 5);
	setwin(win2, '2');

	WINDOW* win3 = newwin(8, 4, 5, 5);
	setwin(win3, '3');

	WINDOW* win4 = newwin(8, 4, 5, 5);
	setwin(win4, '4');

	wrefresh(win1); sleep(1);
	wrefresh(win2); sleep(1);
	wrefresh(win3); sleep(1);
	wrefresh(win4); sleep(1);

	touchwin(win2);

	wrefresh(win1); sleep(1);
	wrefresh(win2); sleep(1);
	wrefresh(win3); sleep(1);
	wrefresh(win4); sleep(1);


	sleep(3);

	endwin();
}
