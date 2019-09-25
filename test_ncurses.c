#include <ncurses.h>
#include <stdio.h>

int main()
{
    char c;

    WINDOW *win = newwin(20, 20, 100, 100);

    initscr();
    wprintw(win, "Press a key to exit the shell\n");
    while((c = getch())) {
	 waddch(win, c | A_BOLD);
    }
    endwin();
    return 0;
}
