#include "resources.h"

// Function for creating files
struct FIL *touch(struct DIR *curr, char *name)
{
	void append(struct DIR *, char *);
	struct FIL *file;

	if (curr == NULL) {
		printf("touch: cannot create a file in a non-existent directory\n");
		return NULL;
	} else if (search(curr, name) != NULL) {
		printf("touch: cannot create file '%s': File exists\n", name);
		return NULL;
	}

	file = malloc(sizeof(struct FIL));
	file->name = name;
	file->tag = 'f';

	append(curr, (char *) file);
	curr->list = list_sort(curr->list);

	return file;
}

// Function for writing files
void _write(struct FIL *file)
{
	if (file->name == NULL)
		printf("Program Error:\t Opening an unnamed file\n");
	else
		printf("File name: %s\n", file->name);
}