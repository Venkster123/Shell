#include "resources.h"

// Merge sort an item list (lexicographic order)
struct ITEM_LIST *list_sort(struct ITEM_LIST *list)
{
	static int counter = 0;
	struct ITEM_LIST *end = list;
	struct ITEM_LIST *a = NULL;
	struct ITEM_LIST *b = NULL;
	struct ITEM_LIST *sorted;
	struct ITEM_LIST *start;
	char *aptr;
	char *bptr;
	int size;
	int i;

	counter++;
	if (counter > 25)
		return NULL;

	if (list == NULL) {
		printf("Empty list\n");
		return NULL;
	} else if (list->next == NULL) {
		printf("One element list\n");
		return list;
	}

	printf("LISTING:\n");
	
	// Find the size of the list
	size = length(list);

	printf("Length of list: %d\n", size);

	// Split the list into a and b
	a = list;
	start = a;
	end = list;
	i = 0;
	while (i < size/2) {
		end = end->next;
		a = end;
		a->next = NULL;
		a = a->next;
		i++;
	}
	
	a = NULL;
	a = start;
	b = end;

	printf("Length of a: %d, b: %d\n", length(a), length(b));

	if (a == NULL)
		printf("list a is now null\n");
	if (b == NULL)
		printf("list b is now null\n");

	// Merge sort a and b
	a = list_sort(a);
	b = list_sort(b);

	// Merge lists a and b
	list = sorted;
	while (a != NULL & b != NULL) {
		sorted = malloc(sizeof(struct ITEM_LIST));

		if (*(a->sptr) == 'd')
			aptr = ((struct DIR *)(a->sptr))->name;
		else
			aptr = ((struct DIR *)(a->sptr))->name;

		if (*(b->sptr) == 'd')
			bptr = ((struct DIR *)(b->sptr))->name;
		else
			bptr = ((struct DIR *)(b->sptr))->name;

		printf("aptr: %s, bptr: %s", aptr, bptr);

		if (strcmp(aptr, bptr) > 0) {
			sorted = b;
			b = b->next;
		} else {
			sorted = a;
			a = a->next;
		}
		
		sorted = sorted->next;
	}

	// Add tails of a or b
	printf("Adding remnants of list a\n");
	i = 0;
	while (a != NULL) {
		sorted = malloc(sizeof(struct ITEM_LIST));
		sorted = a;
		a = a->next;
		sorted = sorted->next;
		i++;
	}
	printf("%d elements in a were remaining\n", i);

	printf("Adding remnants of list b\n");
	i = 0;
	while (b != NULL) {
		sorted = malloc(sizeof(struct ITEM_LIST));
		sorted = b;
		b = b->next;
		sorted = sorted->next;
	}
	printf("%d elements in a were remaining\n", i);

	return list;
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
	struct FILE *file;
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
			file = (struct FILE *) head->sptr;
			printf("%s%c", file->name, (end) ? '\n' : '\t');
			break;
		}

		head = head->next;
	}
}
