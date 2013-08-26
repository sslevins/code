#include <curses.h>

void main()
{
	initscr();

	int y = 0;
	int x = 0;

	for (y = 0; y < LINES-1; y++)
		for (x = 0; x < COLS; x++)
			mvaddch(y, x, '+');

	mvprintw(LINES-1, 0, "please input a char: ");
	refresh();

	WINDOW* win1 = NULL;
	WINDOW* win2 = NULL;
	WINDOW* win3 = NULL;
	WINDOW* win4 = NULL;

	win1 = newwin(4, 4, 10, 10);
	win2 = newwin(4, 4, 10, 10);
	win3 = newwin(4, 4, 10, 10);
	win4 = newwin(4, 4, 10, 10);

	box(win1, '|', '-');
	box(win2, '|', '-');
	box(win3, '|', '-');
	box(win4, '|', '-');

	mvwaddch(win1, 1, 1, '1');
	mvwaddch(win2, 1, 1, '2');
	mvwaddch(win3, 1, 1, '3');
	mvwaddch(win4, 1, 1, '4');

	int c = 0;
	do {
		c = getch();
		switch (c)
		{
			case 'a':
				wmove(stdscr, LINES-1, 21);
				touchwin(win1);
				wrefresh(win1);
				break;

			case 'b':
				wmove(stdscr, LINES-1, 21);
				touchwin(win2);
				wrefresh(win2);
				break;

			case 'c':
				wmove(stdscr, LINES-1, 21);
				touchwin(win3);
				wrefresh(win3);
				break;

			case 'd':
				wmove(stdscr, LINES-1, 21);
				touchwin(win4);
				wrefresh(win4);
				break;

			default:
				wmove(stdscr, LINES-1, 21);
				touchwin(stdscr);
				wrefresh(stdscr);
		}
	
	} while (c != 'q');

	endwin();
}
