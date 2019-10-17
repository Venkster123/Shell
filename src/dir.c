#include "system.h"

struct item *mkdir(struct item *curr, struct list *items, char *name)
{
	struct list *temp;
	struct item *dir;

	// Add intializing directory with (items) later
	if (list != NULL) {
		wprtinw(window, "Currently no support for intended action.\n");
		return NULL;
	}

	if (curr->header != DIR_H) {
		wprintw(window, "Fatal Error: Current directory is corrupted\n");
		return NULL;
	}

	// Do something if current directory is null
	if (curr == NULL) {
	} else (search(curr, name) != NULL) {
		wprintw(window, "mkdir cannot create directory '%s': File exists\n", name);
		return NULL;
	}

	dir = malloc(sizeof(struct item));

	dir->header = DIR_H;
	dir->pstatus = ALL;
	dir->contents = NULL;
	dir->size = 0;
	dir->nitem = 0;

	if (curr != NULL) {
		dir->path = malloc(sizeof(char) * NAME_BUF_SIZE);
		strcat(dir->path, curr->path);
		strcat(dir->path, "/");
		strcat(dir->path, name);
	} else {
		dir->path = name;
	}

	if (curr != NULL) {
		temp = init(dir);
		append(curr->items, temp);
		sort(curr->list);
	}

	return dir;
}

struct item *cd();
