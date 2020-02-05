#include <ncurses.h>

#include <iostream>

#include "dir.h"
#include "window.h"
#include "parser.h"
#include "machine.h"

using namespace std;

int main()
{
	initscr();

	machine main("nokia");
	main();

	endwin();
}
