#include "system.h"

// Import global system variables
__uint8_t status = NORMAL;

int main()
{
	initscr();
	noecho();
	
	WINDOW *window = stdscr;
	
	keypad(window, TRUE);
	scrollok(window, TRUE);

	// Start the shell with root
	struct item *root = mkdir(window, NULL, NULL, "~");
	struct item *curr = root;
	struct item *dir;
	char *name = "shell";
	char *input;

	while (status == NORMAL) {
		wprintw(window, "%s:%s$ ", name, curr->path);

		input = get(window);
		dir = parser(window, root, curr, input);

		if (dir != NULL && dir->header == DIR_H)
			curr = dir;
	}

	delwin(window);
	endwin();
}
