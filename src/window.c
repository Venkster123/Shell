#include "system.h"

char *get(WINDOW *window)
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
				input--;
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
