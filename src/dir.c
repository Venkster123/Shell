#include "system.h"
//#include "debug.h"

struct item *mkdir(WINDOW *window, struct item *curr, struct list *items, char *name)
{
	wprintw(window, "Here");
	struct list *temp;
	struct item *dir;

	// Add intializing directory with (items) later
	if (items != NULL) {
		wprintw(window, "Currently no support for intended action.\n");
		return NULL;
	}

	if (curr != NULL && curr->header != DIR_H) {
		wprintw(window, "Fatal Error: Current directory is corrupted\n");
		return NULL;
	}

	// Do something if current directory is null
	if (curr == NULL) {
	} else if (search(curr, name) != NULL) {
		wprintw(window, "mkdir cannot create directory '%s': File exists\n", name);
		return NULL;
	}

	dir = malloc(sizeof(struct item));

	dir->header = DIR_H;
	dir->pstatus = ALL;
	dir->contents = NULL;
	dir->size = 0;
	dir->nitem = 0;

	dir->name = malloc(sizeof(char) * NAME_BUF_SIZE);
	strcat(dir->name, name);

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
		//println(window, temp);
		curr->items = append(curr->items, temp);
		//sort(curr->items);
	}

	return dir;
}

struct item *cd();

struct item *search(struct item *curr, char *name)
{
	struct list *head = curr->items;

	while (head != NULL) {
		if (strcmp(head->curr->name, name) == 0)
			return head->curr;
		head = head->next;
	}

	return NULL;
}

void list_dir(WINDOW *window, struct item *curr)
{
	struct list *head = curr->items;
	bool end = false;

	wprintw(window, "Listing directory\n");

	if (curr->header == FILE_H) {
		wprintw(window, "%s\n", curr->name);
		return;
	}

	while (head != NULL) {
		wprintw(window, "Looping\n");
		end = (head->next == NULL);
		wprintw(window, "%s%c", head->curr->name, (end) ? '\n' : '\t');
	}
}
