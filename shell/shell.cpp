#include <ncurses.h>

#include <iostream>

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

	// wprintw(stdscr, "sdfsdfds");

	window scr(stdscr);

	scr("sdfsd");
	scr.printf("this is a test");

	scr << "\nfdsfd -- " << window::w_endl << "syay\n";

	int ch = wgetch(stdscr);

	scr << "read char: " << ch << window::w_endl;
	scr << "reading line:";

	string line = scr.get_line(window::w_noecho);

	scr << "you entered: " << line  << window::w_endl;
	scr << line << window::w_endl;

	vector <string> cmds = get_flags(line);

	for (string s : cmds)
		scr << "cmd arg: " << s << window::w_endl;

	refresh();
	getch();

	endwin();
}
