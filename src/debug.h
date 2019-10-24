#ifndef DEBUG_H
#define DEBUG_H

void println(WINDOW *window, struct list *node)
{
	wprintw(window, "Name: %s, Path: %s\n", node->curr->name, node->curr->path);
}

#endif
