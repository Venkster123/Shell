#include <ncurses.h>

#include <iostream>

#include "dir.h"
#include "window.h"
#include "parser.h"

using namespace std;

int main()
{
	initscr();

	// enable filtering
	// of character before
	// outputting it
	// noecho();

	window scr(stdscr);

	dir *root = new dir("", nullptr);
	string name = "nokia";

	string input;
	while (true) {
		scr << name << ": " << root->path() << " $ ";
		input = scr.get_line(window::w_noecho);
		scr << "--" << input << window::w_endl;
	}

	endwin();
}
