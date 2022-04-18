#include "person.h"
#include "file_utils.h"

int main(int argc, char const *argv[])
{
    FILE *file = fopen("liste_nom.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 0;
    }
    List in_oder_list = NULL;

    parse_file(file, &in_oder_list);
    fclose(file);

    print_list(in_oder_list);

    free_list(in_oder_list);

    return 0;
}
