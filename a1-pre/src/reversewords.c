#include "list.h"
#include "common.h"
#include "list_util.h"

int main(int argc, char **argv)
{
    for (int i = 1; i<argc; ++i)
    {
        /* Set filename. */
        char *filename = argv[i];

        /* Create a list with the compare_char function. */
        list_t *list = list_create(compare_char);

        /* Open file object. */
        FILE *inp = fopen(filename, "r");

        /* Tokenize file. */
        tokenize_file(inp, list);

        /* Close file */
        fclose(inp);

        /* Sort and print list. */
        list_sort(list);

        list_reverse(list);

        list_print(list, 0, " ");
    }
    return 0;
}
