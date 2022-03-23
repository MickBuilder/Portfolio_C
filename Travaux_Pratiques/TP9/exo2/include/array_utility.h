#ifndef __ARRAY_UTIILITY_API_H
#define __ARRAY_UTIILITY_API_H

char* create_array(int size);

void destroy_array(char* array);

char** create_two_dimension_array(int lines, int columns);

void destroy_two_dimension_array(char** array, int lines);

void print_two_dimension_array(char** array, int lines, int columns);

void fill_array(char** array, int lines, int columns);

#endif /* __ARRAY_UTIILITY_API_H */