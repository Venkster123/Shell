#include "resources.h"

// Merge sort an item list (lexicographic order)
struct ITEM_LIST *list_sort(struct ITEM_LIST *list)
{
	struct ITEM_LIST *end = list;
	struct ITEM_LIST *a;
	struct ITEM_LIST *b;
	void *aptr;
	void *bptr;
	int size = 0;
	int i;

	if (list == NULL) {
		return NULL;
	} else if (list->next == NULL) {
		return list;
	}

	while (end != NULL) {
		end = end->next;
		size++;
	}

	// Make a the first half of list
	a = NULL;
	end = list;
	for (i = 0; i < size/2; i++) {
		a = end;
		end = end->next;
	}

	// Make b the later half of list
	b = NULL;
	while (end != NULL) {
		b = end;
		end = end->next;
	}

	// Merge sort a and b
	a = list_sort(a);
	b = list_sort(b);

	// Merge a and b
	while (a != NULL && b != NULL) {
		if (*(a->sptr) == 'd')
			aptr = (struct DIR *)(a->sptr);
		else
			aptr 

	printf("Length: %d\n", size);

	return NULL;
}

// Check if item with name exists in current directory
void *search(struct DIR *curr, char *name)
{
	struct ITEM_LIST *head = curr->list;
	struct DIR *dir;
	struct FILE *file;

	while (head != NULL) {
		switch(*(head->sptr)) {
		case 'd':
			dir = (struct DIR *) head->sptr;
			if (strcmp(dir->name, name) == 0)
				return dir;
			break;
		case 'f':
			file = (struct FILE *) head->sptr;
			if (strcmp(file->name, name) == 0)
				return file;
			break;
		}

		head = head->next;
	}

	return NULL;
}

// Return the item(s) with path name
struct ITEM_LIST *get(struct DIR *curr, char *path)
{
	return NULL;
}
