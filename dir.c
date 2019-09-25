#include "resources.h"

// Function for creating the directory
struct DIR *mkdir(struct DIR *curr, struct ITEM_LIST *list, char *name)
{
	struct DIR *dir;

	// Add intializing directory with file list later
	if (list != NULL) {
		printf("Currently no support for intended action.\n");
		return NULL;
	}

	if (curr == NULL) {
	} else if (search(curr, name) != NULL) {
		printf("mkdir: cannot create directory '%s': File exists\n", name);
		return NULL;
	}

	dir = malloc(sizeof(struct DIR));
	dir->tag = 'd';

	/* Assuming that one is creating an empty directory,
	   create a new directory whose parent is curr, path is name,
	   list is empty (NULL) and items is 0 */

	if (curr != NULL) {
		dir->path = malloc(sizeof(char) * NAME_BUF_SIZE);
		strcat(dir->path, curr->path);
		strcat(dir->path, "/");
		strcat(dir->path, name);
	} else {
		dir->path = name;
	}

	dir->name = name;
	dir->parent = curr;
	dir->items = 0;
	dir->list = list;

	if (curr != NULL) {
		append(curr, (char *) dir);
		curr->list = list_sort(curr->list);
	}

	return dir;
}

// Add item to curr's list of _ITEMs
void append(struct DIR *curr, char *item)
{
	struct ITEM_LIST *head;
	struct ITEM_LIST *node;

	node = malloc(sizeof(struct ITEM_LIST));
	node->sptr = item;
	node->next = NULL;

	if (curr->list == NULL) {
		curr->list = node;
	} else {
		head = curr->list;

		while(head->next != NULL)
			head = head->next;

		head->next = node;
	}
}

// Change directory function
struct DIR *cd(struct DIR *curr, char *new)
{
	char *sptr = search(curr, new);

	if (sptr == NULL) {
		printf("cd: %s: No such file or directory\n", new);
	} else {
		if (*sptr != 'd')
			printf("cd: %s: Not a directory\n", new);
		else
			return (struct DIR *)(sptr);
	}

	return NULL;
}

// List directory command from linux
void list_directory(struct DIR *curr)
{
	print(curr->list);
}