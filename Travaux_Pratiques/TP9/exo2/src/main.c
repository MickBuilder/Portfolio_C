#include <stdlib.h>
#include <stdio.h>
#include "array_utility.h"

int main(int argc, char const *argv[])
{
    int line, col;
    char** array;
    do
    {
        printf("Donnez deux dimensions entières: ");
        scanf("%d %d", &line, &col);
    } while (line <= 0 || col <= 0);
    
    array = create_two_dimension_array(line, col);
    fill_array(array, line, col);
    print_two_dimension_array(array, line, col);
    destroy_two_dimension_array(array, line);

    return EXIT_SUCCESS;
}
