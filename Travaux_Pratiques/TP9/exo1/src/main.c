#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

int main(int argc, char const *argv[])
{
    int size;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <size>\n", argv[0]);
        return EXIT_FAILURE;
    }

    size = atoi(argv[1]);

    int* array = create_array(size);
    fill_array(array, size);
    print_array(array, size);
    destroy_array(array);

    return EXIT_SUCCESS;
}
