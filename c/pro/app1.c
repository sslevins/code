#include <curses.h>
#include <stdlib.h>
#include <string.h>

#define CONFIRM 14 

void draw_screen(char * [], int, int, int);
void add_cd();
void save_cd(char* buf);
void update_tracks(char* current_cd);

char* menu[] = {
	"add new CD",
	"find CD",
	"count CDs and total tracks",
	"quit",
	NULL
};

char* ex_menu[] = {
	"add new CD",
	"find CD",
	"count CDs and total tracks",
	"list tracks on CD",
	"update tracks",
	"remove CD",
	"quit",
	NULL
};

static char selected_cd[256];

void main()
{
	memset(selected_cd, 0, 256);

	initscr();

	int ret = 0;
	char c = 0;
	char** options = NULL;

	do {
		clear();
		options = selected_cd[0] ? ex_menu : menu;
		ret = get_choice("Options: ", 
				selected_cd[0] ? ex_menu : menu);

		c = options[ret][0];
		switch (c) {
			case 'a':
				add_cd();
				break;

			case 'f':
				find_cd();
				break;

			case 'c':
				break;

			case 'l':
				break;

			case 'u':
				update_tracks(selected_cd);
				break;

			case 'r':
				break;

			case 'q':
				clear();
				endwin();
				exit(0);
				break;
		}
	
	} while (c != 'q');

	endwin();
}

int get_choice(char* title, char* menu[])
{
	mvprintw(2, 16, "%s", "CD info Application");

	mvprintw(4, 6, title);

	char** options = menu;

	int max_row = 0;
	while (*options != NULL) {
		max_row++;
		options++;
	}
	max_row--;

	int selected_row = 0;
	draw_screen(menu, 5, 10, selected_row);

	keypad(stdscr, TRUE);
	noecho();
	cbreak();

	int c = 0;
	do {
		c = getch();

		switch (c) {
			case KEY_DOWN:
				if (selected_row == max_row)
					selected_row = 0;
				else
					selected_row++;
					
				break;

			case KEY_UP:
				if (selected_row == 0)
					selected_row = max_row;
				else
					selected_row--;
				break;

			//case KEY_ENTER:
			case '\n':
				echo();
				nocbreak();
				keypad(stdscr, FALSE);

				return selected_row;
		}

		draw_screen(menu, 5, 10, selected_row);
	} while (1);
}

void draw_screen(char* menu[], 
	int start_line, int start_col, 
	int selected_row)
{
	int i = 0;
	if (selected_cd[0] != 0) {
		mvprintw(16, 0, "current cd: %s", selected_cd);
		refresh();
	}


	while (*menu != NULL) {
		if (i == selected_row)
			attron(A_REVERSE);

		mvprintw(start_line+i, start_col, 
			"%s", *menu);

		if (i == selected_row)
			attroff(A_REVERSE);

		menu++;
		i++;
	}

	move(start_line+selected_row, start_col-1);

	refresh();
}

void add_cd()
{
	char catalog[128];
	memset(catalog, 0, 128);
	char title[128];
	memset(title, 0, 128);
	char type[128];
	memset(type, 0, 128);
	char artist[128];
	memset(artist, 0, 128);

	clear();

	mvprintw(2, 16, "%s", "CD info Application");
	mvprintw(4, 6, "Add a new CD: ");

	mvprintw(6, 10, "%s", "CD catalog: ");	
	refresh();
	getnstr(catalog, 128);

	mvprintw(7, 10, "%s", "  CD title: ");
	refresh();
	getnstr(title, 128);

	mvprintw(8, 10, "%s", "   CD type: ");
	refresh();
	getnstr(type, 128);

	mvprintw(9, 10, "%s", " CD artist: ");
	refresh();
	getnstr(artist, 128);
	

	char buf[128];
	memset(buf, 0, 128);
	sprintf(buf, "%s,%s,%s,%s", 
			catalog, title, type, artist);

	mvprintw(12, 10, "%s", "Are you sure to input this info: (y/Y)");
	mvprintw(13, 14, "%s", buf);

	noecho();
	cbreak();
	int c = getch();

	if (c == 'y' || c == 'Y') {
		save_cd(buf);
		memset(buf, 0, 128);
		sprintf(buf, "%s/%s", catalog, title);
		strncpy(selected_cd, buf, strlen(buf)+1);
	} else {
		move(13, 0);
		clrtoeol();

		mvprintw(13, 14, "%s", "Cancel");
		refresh();

		sleep(2);
	}

	nocbreak();
	echo();
}

void save_cd(char* buf)
{
	FILE* f = fopen("./cd.data", "a");
	int len = strlen(buf);

	fwrite(buf, 1, len+1, f);

	fclose(f);
}

void update_tracks(char* current_cd)
{
	clear();

	mvprintw(2, 16, "%s", "CD info Application");
	mvprintw(4, 6, "Input a blank line to quit: ");

	noecho();
	cbreak();

	mvprintw(15, 10, "%s", "Re-built tracks on this CD?: (y/Y)");

	int c = getch();
	echo();
	nocbreak();

	//mvprintw(0, 0, "%s %c", "Debug:", c);
	//refresh();

	if (c != 'y' && c != 'Y')
	{
		move(13, 0);
		clrtoeol();

		mvprintw(13, 14, "%s", "Cancel");
		refresh();

		sleep(2);
	} 
	else 
	{

		refresh();
		WINDOW* back = 
				subwin(stdscr, 8, 30, 6, 6);
		box(back, '|', '-');
		wrefresh(back);
	
		WINDOW* fore = 
				subwin(stdscr, 6, 28, 7, 7);

		char name[128]; 
		char time[128]; 
		char format[128]; 
		int j = 0;
		wmove(fore, 0, 0);
		do { 
			j++;
			wprintw(fore, "%s %d %s", 
				"Track", j, "name: "); 
			memset(name, 0, 128);
			wgetstr(fore, name); 
			wrefresh(fore);
			if (strlen(name) == 0)
				break;
			    
		 	wprintw(fore, "%s %d %s",
		  		"Track", j, "time: ");
			memset(time, 0, 128);
			wgetstr(fore, time);
			wrefresh(fore);
			if (strlen(time) == 0)
				break;
				
		  	wprintw(fore, "%s %d %s",
			   "Track", j, "format: ");
			memset(format, 0, 128);
		   	wgetstr(fore, format);
			wrefresh(fore);
			if (strlen(format) == 0)
				break;

		} while (1);

	}
}

