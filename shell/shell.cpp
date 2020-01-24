#include "window.h"
#include "ncurses.h"

int main()
{
	window stdw(stdscr);
	//win << "Hello World" << endl;
	//win("Hello World\n");
	initscr();
	printw("Hello World\n");
	refresh();
	stdw("hi there");
	refresh();
	getch();
	endwin();
}
