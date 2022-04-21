#include "file_utils.h"

void parse_file(FILE *file, List *list) {
    char lastname[BUF_SIZE];
    char firstname[BUF_SIZE];
    int age;

    while (fscanf(file, "%s %s %d", lastname, firstname, &age) == 3) {
        Person *person = create_person(firstname, lastname, age);
        ordered_insert(list, person, name_order);
    }
}