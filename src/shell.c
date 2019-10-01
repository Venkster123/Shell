#include "system.h"
#include <curses.h>

// Import global system variables
__uint8_t status = NORMAL;

int main()
{
    int ses_len = 100;
    char *input;
    char *start;
    int c;

    input = malloc(LINE_BUF_SIZE);
    start = input;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    printw("shell $ ");
    while (ses_len--) {
        c = getch();

        switch(c) {
        case '\n':
            addch(c);
            *input = '\0';
            printw("Entered: [%s]\n", start);
            scrl(1);
            input = start;
            printw("shell $ ");
            break;
        case KEY_BACKSPACE: case KEY_DC:
            printw("\b \b");
            break;
        default:
            addch(c);
            *input++ = c;
            break;
        }

        refresh();
    }
    endwin();
}
