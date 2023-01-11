#include "common.h"
#include "list.h"
#include "list_util.h"


int main(int argc, char **argv)
{
    for (int i = 1; i<argc; ++i)
    {
        char *filename = argv[i];

        printf("%d\n", i);

        list_t *list = list_create(compare_char);

        printf("start tokenizing %s\n", filename);
        tokenize_file((FILE *)filename, list);
        printf("end tokenizing %s\n", filename);
        
        printf("begin printing");
        list_print(list);
    }
    return 0;
}
