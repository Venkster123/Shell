#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

// Define maximum file and line lengths
#define FILE_BUF_SIZE 10000
#define LINE_BUF_SIZE 1000
#define NAME_BUF_SIZE 1000

// Define the file structure
struct FIL {
	char tag;
	char *file;
	char *name;
};

// Define the directory structure
struct DIR {
	char tag;
	int items;
	char *path;
	char *name;
	struct ITEM_LIST *list;
	struct DIR *parent;
};

// Define the file list structure
struct ITEM_LIST {
	char *sptr;
	struct ITEM_LIST *next;
};

// Define the argument structure
struct ARGS {
	char **args;
	int argc;
};

// Functions
extern struct DIR *mkdir(struct DIR *, struct ITEM_LIST *, char *);
extern struct FIL *touch(struct DIR *, char *);

extern void list_directory(struct DIR *);
extern void *search(struct DIR *, char *);
extern void append(struct DIR *, char *);
extern struct DIR *parser(struct DIR *, struct DIR *, char *);
extern struct DIR *cd(struct DIR *, char *);
extern struct ITEM_LIST *list_sort(struct ITEM_LIST *);
extern int length(struct ITEM_LIST *);
extern void print(struct ITEM_LIST *);