#include "window.h"
#include "ncurses.h"

int main()
{
	//win << "Hello World" << endl;
	//win("Hello World\n");
	initscr();
	printw("Hello World\n");
	getch();
	endwin();
}
