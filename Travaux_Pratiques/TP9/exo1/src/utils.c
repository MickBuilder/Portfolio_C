#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

int* create_array(int size) {
    int* array = (int*) malloc(sizeof(int) * size);
    if (array == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(0);
    }
    
    return array;
}

void destroy_array(int* array) {
    if (array != NULL) {
        free(array);
    }
}

void print_array(int* array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void fill_array(int* array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        array[i] = i + 1;
    }
}