#include "system.h"

// Import global system varaibles
extern __uint8_t status;

/*
 * Touch works like touch from linux,
 * taking in only the name of the file
 * and the parent directory as parameters.
 *
 * It does check to make sure that curr
 * is indeed a directory before taking any
 * action - if it turns out this way, the
 * shell's status will be changed to terminate
 * and the shell will exit/terminate.
 *
 * It also exits both if the current directory
 * is NULL (with status QUIT) and if there
 * already exists the file of the name (with
 * status NORMAL)
 *
 * Additional maintenance:
 *  - Add duplicattion prevention
 *  - Add date attirbute initialization
 *    (date last modified and created)
 *  - Add private status initialization
 *  - Check size matters
 */

struct item *touch(struct item *curr, char *name)
{
    struct item *file;
    struct list *node;

    if (curr == NULL) {
	    status = QUIT;
	    return NULL;
    } else if (curr->header == FILE_H) {
	    status = QUIT;
	    return NULL;
    }

    file = malloc(sizeof(struct item));

    file->header = FILE_H;
    file->name = name;
    file->contents = NULL;
    file->items = NULL;
    file->parent = curr;
    file->size = 0x0;
    file->path = curr->path;
    strcat(file->path, "/");
    strcat(file->path, name);

    node = init(file);
    append(curr->items, node);

    return file;
}
