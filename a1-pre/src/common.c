/* Author: Steffen Viken Valvaag <steffenv@cs.uit.no> */
#include "common.h"
#include "list.h"
#include "printing.h"

void tokenize_file(FILE *file, list_t *list)
{
    char *word;
    char buf[101];
    buf[100] = 0;

    while (!feof(file)) {
        /* Skip non-letters */
        fscanf(file, "%*[^a-zA-Z0-9'_]");
        /* Scan up to 100 letters */
        if (fscanf(file, "%100[a-zA-Z0-9'_]", buf) == 1) {
            word = strdup(buf);
            if (word == NULL)
            ERROR_PRINT("out of memory");
            list_addlast(list, word);
        }
    }
}

int compare_char(void *arg1, void *arg2)
{
    const int res = strcmp((char *)arg1, (char *)arg2);
    if (res < 0)
    {
        return 1;
    } else if (res > 0) 
    {
        return -1;
    } else
    {
        return 0;
    }
}