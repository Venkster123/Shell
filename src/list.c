#include "system.h"
#include "debug.h"

struct list *init(struct item *val)
{
    struct list *node;

    node = malloc(sizeof(struct list));
    node->curr = val;
    node->next = NULL;

    return node;
}

struct list *append(struct list *head, struct list *node)
{
    struct list *start = head;

    if (start != NULL) {
	    while (start->next != NULL) {
		    println(stdscr, start);
		    start = start->next;
	    }
	    start->next = node;
    }

    return head;
}

void sort(struct list *head)
{

}
