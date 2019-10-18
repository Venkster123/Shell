#include "system.h"

void setup()
{
	noecho();
	initscr();
	keypad(window, TRUE);
	scrollok(window, TRUE);
}

char *get()
{
	__uint32_t counter;
	char *input;
	char *start;
	int c;

	input = malloc(LINE_BUF_SIZE);
	start = input;
	counter = 0;
	
	while ((c = wgetch(window)) != EOF) {	
		switch(c) {
		case '\n':
			waddch(window, c);
			*input = '\0';
			return start;
		case KEY_BACKSPACE: case KEY_DC:
			if (counter > 0) {
				printw("\b \b");
				counter--;
			}
			break;
		default:
			waddch(window, c);
			*input++ = c;
			counter++;
			break;
		}

		wrefresh(window);
	}

	return NULL;
}
