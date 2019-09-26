#include <stdio.h>

struct _FILE {
    char *name;
    char *path;
    char *contents;
    struct _FILE *parent;
};