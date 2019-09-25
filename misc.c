#include "resources.h"

// Merge sort an item list (lexicographic order)
struct ITEM_LIST *list_sort(struct ITEM_LIST *list)
{
	struct ITEM_LIST *end = list;
	struct ITEM_LIST *tail;
	struct ITEM_LIST *a;
	struct ITEM_LIST *b;
	int size;
	int i;

	if (list == NULL)
			return NULL;
	else if (list->next == NULL)
		return list;

	size = length(list);

	for (i = 0; i < size/2; i++) {
		if (a == NULL) {
			a = malloc(sizeof(struct ITEM_LIST));
			a->sptr = b->sptr;
			a->next = NULL;
			tail = a;
		} else {
			tail->next = malloc(sizeof(struct ITEM_LIST));
			tail = tail->next;
			tail->sptr = end->sptr;
			tail->next = NULL;
		}
	}

	/*b = malloc(sizeof(struct ITEM_LIST));
	start = b;
	while (end != NULL) {
		if (start == NULL)
			start = malloc(sizeof(struct ITEM_LIST));
		start->sptr = end->sptr;
		start = start->next;
		end = end->next;
	}*/
	b = end;

	printf("__LIST(A)__\n");
	print(a);
	printf("__LIST(B)__\n");
	print(b);

	return list;
}

// Check if item with name exists in current directory
void *search(struct DIR *curr, char *name)
{
	struct ITEM_LIST *head = curr->list;
	struct DIR *dir;
	struct FIL *FIL;

	while (head != NULL) {
		switch(*(head->sptr)) {
		case 'd':
			dir = (struct DIR *) head->sptr;
			if (strcmp(dir->name, name) == 0)
				return dir;
			break;
		case 'f':
			FIL = (struct FIL *) head->sptr;
			if (strcmp(FIL->name, name) == 0)
				return FIL;
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

// Return the number of items in the list
int length(struct ITEM_LIST *list)
{
	struct ITEM_LIST *end = list;
	int i = 0;

	while (end != NULL) {
		end = end->next;
		i++;
	}

	return i;
}

// Print the items in the passed ITEM_LIST
void print(struct ITEM_LIST *list)
{
	struct ITEM_LIST *head = list;
	struct FIL *FIL;
	struct DIR *dir;
	bool end = false;

	while (head != NULL) {
		if (head->next == NULL)
			end = true;

		switch(*(head->sptr)) {
		case 'd':
			dir = (struct DIR *) head->sptr;
			printf("%s%c", dir->name, (end) ? '\n' : '\t');
			break;
		case 'f':
			FIL = (struct FIL *) head->sptr;
			printf("%s%c", FIL->name, (end) ? '\n' : '\t');
			break;
		}

		head = head->next;
	}
}
