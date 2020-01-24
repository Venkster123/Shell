#include "window.h"
#include "ncurses.h"

#include <iostream>

using namespace std;

int main()
{
	window fdf(stdscr);
	//win << "Hello World" << endl;
	//win("Hello World\n");
	//initscr();
	// initscr();
	window stdw(stdscr);
	window win(stdscr);
	/*initscr();
	//printw("Hello World\n");
	//printw("Hi thee");
	refresh();*/
	cout << "here" << endl;
	stdw.printf("hi there");
	fdf.printf("fdsfdsfs");
	win.printf("dsfsd");
	/*refresh();
	getch();
	endwin();*/
	getch();
	endwin();
}
