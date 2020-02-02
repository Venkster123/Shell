#include <ncurses.h>

#include <iostream>

#include "window.h"

using namespace std;

int main()
{
	initscr();

	// wprintw(stdscr, "sdfsdfds");

	window scr(stdscr);

	scr("sdfsd");
	scr.printf("this is a test");

	scr << "\nfdsfd -- " << w_endl << "syay\n";

	refresh();
	getch();

	endwin();
}
