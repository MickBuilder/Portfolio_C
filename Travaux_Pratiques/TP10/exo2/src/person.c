#include <stdlib.h>
#include <string.h>
#include "person.h"

/**
 * Create a new person with the given first name, last name, and age
 * 
 * @param first_name The first name of the person.
 * @param last_name The last name of the person.
 * @param age The age of the person.
 */
Person* create_person(char* first_name, char* last_name, int age) {
    Person* person = (Person*)malloc(sizeof(Person));
    person->first_name = first_name;
    person->last_name = last_name;
    person->age = age;
    person->next = NULL;

    return person;
}

/**
 * 
 * 
 * @param person1 The first person to compare.
 * @param person2 the person we are comparing to person1
 */
int age_order(Person* person1, Person* person2) {
    return person1->age - person2->age;
}

int name_order(Person* person1, Person* person2) {
    /*while ((order(list->next, person) < 0) && (list->next != NULL)) {
        list = list->next;
    }

    if(  == 0){

    }
    list->next = person;*/
    
    return strcmp(person1->last_name, person2->last_name);
}

void ordered_insert(List* list, Person* person, int (*order)(Person*, Person*)) {
    while ((*order)((*list)->next, person) < 0 && (*list)->next != NULL) {
        list = (*list)->next;
    }

    person->next = (*list)->next;
    (*list)->next = person;
}

/**
 * Prints the list
 * 
 * @param list the list to print
 */
void print_list(List list) {
    Person* current = list;
    while (current != NULL) {
        printf("FirstName: %s, LastName: %s, Age: %d\n", current->first_name, current->last_name, current->age);
        current = current->next;
    }
}

/**
 * Free the memory allocated for the list
 * 
 * @param list the list to be freed
 */
void free_list(List list) {
    Person* current = list;
    while (current != NULL) {
        Person* next = current->next;
        free(current->first_name);
        free(current->last_name);
        free(current);
        current = next;
    }
}