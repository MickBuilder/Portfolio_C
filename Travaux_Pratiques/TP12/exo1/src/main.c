#include <stdio.h>
#include "list_utilities.h"

int main(int argc, char const *argv[])
{
    FILE *file = fopen("data/Germinal.txt", "r");
    List list = NULL;

    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    read_file(file, &list);

    fclose(file);

    printf("%d different words found in Germinal\n", list_size(list));

    delete_list(list);

    return 0;
}
