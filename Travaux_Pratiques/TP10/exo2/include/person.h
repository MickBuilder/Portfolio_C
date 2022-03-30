#ifndef __PERSON_H__
#define __PERSON_H__

typedef struct cell
{
    char* first_name;
    char* last_name;
    int age;
    struct cell* next;
} Person, *List;


Person* create_cell(char* first_name, char* last_name, int age);

int age_order(Person* cell1, Person* cell2);

int name_order(Person* cell1, Person* cell2);

void ordered_insert(List* list, Person* cell, int (*order)(Person*, Person*));

void print_list(List list);

void free_list(List list);

#endif /* __PERSON_H__ */