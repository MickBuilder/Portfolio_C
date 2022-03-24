#ifndef __ARGS_UTIILITY_API_H
#define __ARGS_UTIILITY_API_H

char* create_string(int str_len);

void destroy_string(char* string);

char** create_string_array(int size);

void delete_string_array(char** array, int size);

void print_string_array(char** array, int size);

/*void fill_array(char** array, int lines, int columns);*/

#endif /* __ARGS_UTIILITY_API_H */