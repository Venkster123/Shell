#include "system.h"

struct list *init(struct item *val)
{
    struct list *node;

    node = malloc(sizeof(struct list));
    node->curr = val;
    node->next = NULL;

    return node;
}