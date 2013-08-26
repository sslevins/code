#include <curses.h>

void main()
{
	initscr();


	noecho();
	keypad(stdscr, TRUE);

	int c = 0;
	do {
		c = getch();
		switch (c)
		{
			case KEY_UP:
				move(0, 0);
				clrtoeol();
				printw("you just press up_key");
				break;

			case KEY_DOWN:
				move(0, 0);
				clrtoeol();
				printw("you just press down_key");
				break;

			case KEY_LEFT:
				move(0, 0);
				clrtoeol();
				printw("you just press left_key");
				break;

			case KEY_RIGHT:
				move(0, 0);
				clrtoeol();
				printw("you just press right_key");
				break;
		}

		refresh();
	} while (c != 'q');


	sleep(3);

	endwin();
}
