#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "args_utility.h"

int main(int argc, char const *argv[])
{
    int i;
    char **array;
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <arg1> <arg2> ... <argn>\n", argv[0]);
        return EXIT_FAILURE;
    }

    array = create_string_array(argc);

    for(i = 0; i < argc; i++) {
        char* arg = create_string(strlen(argv[i]) + 1);
        strcpy(arg, argv[i]);
        array[i] = arg;
    }

    print_string_array(array, argc);
    delete_string_array(array, argc);

    return EXIT_SUCCESS;
}
