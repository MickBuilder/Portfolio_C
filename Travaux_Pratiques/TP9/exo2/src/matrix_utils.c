#include <stdlib.h>
#include <stdio.h>
#include "array_utility.h"

char* create_array(int size) {
    char* array = (char*) malloc(sizeof(char) * size);
    if (array == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(0);
    }
    
    return array;
}

void destroy_array(char* array) {
    if (array != NULL) {
        free(array);
    }
}

char** create_two_dimension_array(int lines, int columns) {
    int i;
    char** array = (char**) malloc(sizeof(char*) * lines);
    if (array == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(0);
    }

    for (i = 0; i < columns; i++) {
        array[i] = create_array(columns);
    }

    return array;
}

void destroy_two_dimension_array(char** array, int lines) {
    int i;
    if (array == NULL) {return;}
    for (i = 0; i < lines; i++) {
        destroy_array(array[i]);
    }

    free(array);
}

void print_two_dimension_array(char** array, int lines, int columns) {
    int i, j;
    for (i = 0; i < lines; i++) {
        for (j = 0; j < columns; j++) {
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
}

void fill_array(char** array, int lines, int columns) {
    int i, j;
    for (i = 0; i < lines; i++) {
        for (j = 0; j < columns; j++) {
            array[i][j] = 'a' + (i + j) % 26;
        }
    }
}