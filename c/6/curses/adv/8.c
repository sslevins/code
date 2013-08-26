#include <curses.h>

void main()
{
	initscr();

	if(has_colors() != TRUE)
		goto err;

	if (start_color() != OK)
		goto err;
	
	init_pair(10, COLOR_RED, COLOR_GREEN);
	init_pair(20, COLOR_BLACK, COLOR_YELLOW);
	init_pair(30, COLOR_WHITE, COLOR_BLUE);

	attrset(COLOR_PAIR(10));
	mvprintw(0, 0, "hello world");
	refresh();
	sleep(2);

	attrset(COLOR_PAIR(20)|A_BOLD);
	mvprintw(2, 2, "goodbye");
	refresh();
	sleep(2);

	attrset(COLOR_PAIR(30)|A_BOLD|A_UNDERLINE);
	mvprintw(4, 4, "hello world");
	refresh();
	sleep(20);

err:
	endwin();
}

