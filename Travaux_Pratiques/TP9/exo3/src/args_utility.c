#include <stdlib.h>
#include <stdio.h>
#include "args_utility.h"

char* create_string(int str_len) {
    char* string = (char*) malloc(sizeof(char) * str_len);
    if (string == NULL) {
        fprintf(stderr, "Error: No memory\n");
        exit(0);
    }
    
    return string;
}

void destroy_string(char* string) {
    if (string != NULL) {
        free(string);
    }
}

char** create_string_array(int size) {
    char** array = (char**) malloc(sizeof(char*) * size);
    if (array == NULL) {
        fprintf(stderr, "Error: No more memory\n");
        exit(0);
    }

    return array;
}

void delete_string_array(char** array, int size) {
    int i;
    if (array == NULL) {return;}
    for (i = 0; i < size; i++) {
        destroy_string(array[i]);
    }

    free(array);
}

void print_string_array(char** array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("arg[%d] : %s\n", i, array[i]);
    }
}