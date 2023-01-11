/* Author: Christian Salomonsen*/
// #include "common.h"
#include "list.h"

typedef struct list
{
    void *elem;
    list_t *next;
    list_t *prev;
} list_t;

list_t *list_create(cmpfunc_t cmpfunc)
{
    // Allocate memory for list
    list_t *list = malloc(sizeof(list_t));

    // Confirm enoguh memory available
    if (list == NULL)
        ERROR_PRINT("out of memory");

    // initialize values and next/prev pointers
    list->elem = NULL;
    list->next = NULL;
    list->prev = NULL;
    return list;
}

// void list_destroy(list_t *list)
// {

// }