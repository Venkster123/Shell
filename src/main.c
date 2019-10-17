#include "system.h"

// Import global system variables
__uint8_t status = NORMAL;

int main()
{
	// Start the shell with root
	struct item *root = mkdir(NULL, NULL, "~");
	struct item *curr = root;
	struct *name = "shell';
	char *input;
	
	window = stdscr;
	setup();

	while (status == NORMAL) {
		wprintw(window, "%s:%s$", name, curr->path);

		input = get();
		dir = parser(input);

		if (dir != NULL && dir->header == HEADER_H)
			curr = dir;
	}

	delwin(window);
	endwin(window);
}
