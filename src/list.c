#include "system.h"

struct list *init(struct item *val)
{
    struct list *node;

    node = malloc(sizeof(struct list));
    node->curr = val;
    node->next = NULL;

    return node;
}

void append(struct list *head, struct list *node)
{
    struct list *start = head;

    if (head == NULL)
        return node;

    while (start->next != NULL)
        start = start->next;
    start->next = node;
}

void sort(struct list *head)
{

}
