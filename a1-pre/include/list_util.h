#ifndef LISTUTIL_H
#define LISTUTIL_H

#include "list.h"

typedef struct list_node list_node_t;

/* 
 * Swaps the given node with its right neighbor.
 */
void list_nodeswap(list_node_t *node);

/* 
 * Print the (char *) elements of the given list.
 */
void list_print(list_t *list, int brackets, char *sep);

/* 
 * Reverse the given list.
 * Implementation inspired by: https://gist.github.com/icheishvili/4190607#file-list-c-L149-L160
 */
void list_reverse(list_t *list);

#endif