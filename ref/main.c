#include "resources.h"

// Shell's entry point
int main()
{
	// Starting settings
	struct DIR *root = mkdir(NULL, NULL, "~");
	struct DIR *curr = root;
	struct DIR *dir;
	char *name = "shell";

	char *input = malloc(sizeof(char) * LINE_BUF_SIZE);
	char *start = input;
	char c;

	while(true) {
		printf("%s:%s$ ", name, curr->path);

		input = start;
		while ((c = getchar()) != EOF) {
			if (c == '\n') {
				*input = '\0';
				break;
			} else {
				*input++ = c;
			}
		}

		dir = parser(root, curr, start);

		if (dir != NULL)
			curr = dir;
	}
}