#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
    person->first_name = (char*)malloc(sizeof(char) * (strlen(first_name) + 1));
    person->last_name = (char*)malloc(sizeof(char) * (strlen(last_name) + 1));
    strcpy(person->first_name, first_name);
    strcpy(person->last_name, last_name);
    person->age = age;
    person->next = NULL;

    return person;
}


/**
 * If the age of the first person is equal to the age of the second person, then the function returns
 * the result of the name_order function, otherwise it returns the difference between the age of the
 * first person and the age of the second person
 * 
 * @param person1 The first person to compare
 * @param person2 The second person to compare.
 * 
 * @return the result of the comparison between the two persons.
 */
int age_order(Person* person1, Person* person2) {
    int age_comparison = person1->age - person2->age;
    return age_comparison == 0 ? name_order(person1, person2) : age_comparison;
}


/**
 * If the last names are the same, then compare the ages, otherwise compare the last names
 * 
 * @param person1 A pointer to the first person to compare.
 * @param person2 The second person to compare.
 * 
 * @return the result of the comparison between the two names. If the names are equal, the function
 * returns the result of the comparison between the two ages.
 */
int name_order(Person* person1, Person* person2) {    
    int name_comparison = strcmp(person1->last_name, person2->last_name);
    return name_comparison == 0 ? age_order(person1, person2) : name_comparison;
}

void print_person(Person* person) {
    printf("%s %s %d\n", person->first_name, person->last_name, person->age);
}

/**
 * It takes a list, a person, and a function pointer to a function that compares two people and returns
 * an int. It then inserts the person into the list in the correct order
 * 
 * @param list a pointer to a pointer to a Person struct
 * @param person The person to be inserted
 * @param order a function pointer to a function that takes two Person* and returns an int.
 */
void ordered_insert(List* list, Person* person, int (*order)(Person*, Person*)) {
    /*printf("In insertion func ↡↡↝↡\n");
    print_person(person);*/

    if (*list == NULL) {
        *list = person;
    } else {
        Person* current = *list;
        while (current->next != NULL && order(person, current->next) >= 0) {
            current = current->next;
        }

        person->next = current->next;
        current->next = person;
    }
}

/**
 * Prints the list
 * 
 * @param list the list to print
 */
void print_list(List list) {
    Person* current = list;
    int i = 1;
    while (current != NULL) {
        printf("%2d => [%s, %s, %d]\n", i, current->last_name, current->first_name, current->age);
        current = current->next;
        i++;
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