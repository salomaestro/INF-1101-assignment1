#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"


typedef struct list_node list_node_t;
typedef struct list_node
{
    void *elem;
    list_node_t *next;
    list_node_t *prev;
} list_node_t;


typedef struct list list_t;
typedef struct list
{
    list_node_t *head;
    int size;
} list_t;

/* Creates a node which preferably lives inside a list. */
list_node_t *list_node_create(void *elem)
{
    list_node_t *node = (list_node_t *)malloc(sizeof(list_node_t));

    if (node == NULL)
    {
        printf("OUT OF MEMORY");
        return node;
    }

    node->elem = elem;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

list_t *list_create(void *elem) {
    list_t *list = (list_t *)malloc(sizeof(list_t));
    list_node_t *head = list_node_create(elem);

    if (list == NULL)
    {
        printf("OUT OF MEMORY");
        return list;
    }

    list->size = 1;
    list->head = head;

    return list;
}

void list_destroy(list_t *list)
{
    /* NB! greatly inspired by: https://stackoverflow.com/a/18412733
     * I tried to find my own way of doing it, but I once you
     * see a good implementation it is hard to forget about it ;).
     */
    list_node_t *current = list->head;

    /* Define a temporary list node to store next pointer in while destroying
     * the 'current' node.
     */
    list_node_t *temp;

    /* Iterate till current node is NULL */
    while (current != NULL)
    {

        /* Store next pointer of current node in temp node
         * such that we can free the memory position of the
         * current node without losing the pointer to the
         * next node.
         */
        temp = current->next;
        free(current);

        /* Assign current as the previously temporarily assigned
         * next node.
         */
        current = temp;
    }
    free(list);
}

int list_size(list_t *list)
{
    int retval = list->size;
    return retval;
}

int list_addfirst(list_t *list, void *elem)
{
    if (list == NULL)
    {
        return 0;
    }

    /* Generate a new node and put 'elem' inside its 'elem' slot. */
    list_node_t *new_node = list_node_create(elem);

    /* Set the next of the node as the list's head. */
    new_node->next = list->head;

    /* Set lists head as the new node. */
    list->head = new_node;

    /* Set head's prev as the new node. */
    new_node->next->prev = new_node;

    /* Update size of list */
    ++list->size;

    return 1;
}

int list_addlast(list_t *list, void *elem)
{
    /* Check that list exist. */
    if (list == NULL)
    {
        return 0;
    }

    /* Construct new node with new data. */
    list_node_t *new_node = list_node_create(elem);

    /* Set current node as head, then iterate till last node. */
    list_node_t *current = list->head;
    
    while (current->next != NULL)
    {
        current = current->next;
    }
    
    /* Set next of last node to the new node. */
    current->next = new_node;

    /* Set the prev of the new node as the formerly last node. */
    new_node->prev = current;
    
    /* Increase list size by one. */
    ++list->size;

    return 1;
}

// int list_addfirst(list_t *list, void *elem)
// {
//     if (list == NULL) 
//     {
//         return 0;
//     }
//     /* Create a new element represent the original head node
//      * of the input linked list.
//      */
//     list_t *old_head = list_create(list->elem);
//     old_head->next = list->next;

//     /* Owerwrite the old head's elem with the argument element,
//      * then overwrite the next-pointer to point to the old head node,
//      * then set old head's previous node as the head of the list.
//      */
//     list->elem = elem;
//     list->next = old_head;
//     old_head->prev = list;

//     if (list->elem != elem) 
//     {
//         return 0;
//     }

//     return 1;
// }

// int list_addlast(list_t *list, void *elem)
// {
//     if (list == NULL)
//     {
//         return 0;
//     }
//     /* Initialize 'empty' node not otherwise connected
//      * to the input list.
//      */
//     list_t *new_last = list_create(elem);

//     /* Iterate till last node of linked list */
//     while (list->next != NULL) 
//     {
//         list = list->next;
//     }

//     /* Set the last-nodes pointer to next as the new node. */
//     list->next = new_last;

//     /* Remember to set the new last node's prev pointer to the
//      * previously last node.
//      */
//     new_last->prev = list;

//     /* Try to catch any errors with setting the new last node. */
//     if (new_last->elem != elem) 
//     {
//         return 0;
//     }
//     return 1;
// }

// void *list_popfirst(list_t *list)
// {
//     /* Save the value of the first node. */
//     void *elem = list->elem;

//     /* Set the current evaluated node to be the head. */
//     list_t *current = list;
//     while (current->next != NULL)
//     {
//         /* Redefine current node such that it skips the head.
//          * 'current' lies one ahead of 'list' therefore hand
//          * 'elem' of current over to list and iterate till the
//          * second to last node. 
//          */
//         current = current->next;
//         list->elem = current->elem;
//         list = current;
//     }

//     /* Set the second to last node's next node to NULL, if this
//      * is not done there would be a duplicate of the last elem
//      * in the list.
//      */
//     current->prev->next = NULL;

//     return elem;
// }

// void *list_poplast(list_t *list)
// {
//     /* Iterate till the second to last element */
//     while (list->next->next != NULL)
//     {
//         list = list->next;
//     }

//     /* Store value from node being removed. */
//     void *elem = list->next->elem;

//     /* Set second to last node's next-pointer to NULL */
//     list->next = NULL;

//     return elem;
// }

// int list_contains(list_t *list, void *elem)
// {

// }

void list_print(list_t *list)
{
    list_node_t *current = list->head;

    if (current == NULL)
    {
        printf("Head node not initialized!");
    }

    /* For indicating list I like to use regular square brackets. */
    printf("[");

    /* Iterate till last node */
    while (current->next != NULL)
    {
        /* Because elem is a void pointer type-cast it to a string. */
        printf("%s, ", (char*)current->elem);
        current = current->next;
    }

    /* Print last element */
    printf("%s]\n", (char*)current->elem);
}

// typedef struct list_iter list_iter_t;
// typedef struct list_iter
// {
//     list_t *list_head;
// } list_iter;

// list_iter_t *list_createiter(list_t *list)
// {
//     list_iter_t *list_iter = (list_iter_t*)malloc(sizeof(list_iter_t));
//     list_iter->list_head = list;

//     return list_iter;
// }

int main()
{
    char *w1 = "Hello";
    char *w2 = "world";
    char *w3 = "yaya";
    char *w4 = "yeyeye";

    list_t *my_list = list_create(w1);

    list_print(my_list);

    printf("add last: %d\n", list_addlast(my_list, w2));
    printf("add last: %d\n", list_addlast(my_list, w3));
    printf("add first: %d\n", list_addfirst(my_list, w4));
    
    list_print(my_list);

    printf("size = %d\n", list_size(my_list));

    // printf("%s\n", (char*)list_popfirst(my_list));

    // list_print(my_list);

    // printf("%s\n", (char*)list_poplast(my_list));

    // list_print(my_list);

    // list_destroy(my_list);

    return 0;
}