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
void list_print(list_t *list);

#endif