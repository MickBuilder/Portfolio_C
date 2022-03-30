#include "utils_functions.h"

void swap_mem_quick_version(void* z1, void* z2, size_t size)
{
    void* tmp = malloc(size);
    memcpy(tmp, z1, size);
    memcpy(z1, z2, size);
    memcpy(z2, tmp, size);
    free(tmp);
}

void swap_mem(void* z1, void* z2, size_t size) {
    int i;
    char tmp_data;
    char *byte_data_1, *byte_data_2;

    if (z1 == NULL || z2 == NULL) {return;}
    
    byte_data_1 = (char*)z1;
    byte_data_2 = (char*)z2;

    for (i = 0; i < size; i++)
    {
        tmp_data = byte_data_1[i];
        byte_data_1[i] = byte_data_2[i];
        byte_data_2[i] = tmp_data;
    }
}

void display_array(int* array, int size)
{
    int i;
    char separator = ' ';
    printf("[");
    for (i = 0; i < size; i++)
    {
        printf("%c%d", separator, array[i]);
        separator = ',';
    }
    printf("]\n");
}

void perform_swap_on_int(void* data1, void* data2, size_t size)
{
    printf("Before swapping int\n==================\n");
    printf("Int 1: %d\tInt 2: %d\n", *(int*)data1, *(int*)data2);

    swap_mem(data1, data2, size);
    /*swap_mem_quick_version(data1, data2, size);*/

    printf("After swapping int\n==================\n");
    printf("Int 1: %d\tInt 2: %d\n", *(int*)data1, *(int*)data2);
}

void perform_swap_on_char(void* data1, void* data2, size_t size)
{
    printf("\nBefore swapping data\n==================\n");
    printf("Char 1: %c\tChar 2: %c\n", *(char*)data1, *(char*)data2);

    swap_mem(data1, data2, size);
    /*swap_mem_quick_version(data1, data2, size);*/

    printf("After swapping data\n==================\n");
    printf("Char 1: %c\tChar 2: %c\n", *(char*)data1, *(char*)data2);
}

void perform_swap_on_real(void* data1, void* data2, size_t size)
{
    printf("\nBefore swapping data\n==================\n");
    printf("Double/Float 1: %f\tDouble/Float 2: %f\n", *(float*)data1, *(float*)data2);

    swap_mem(data1, data2, size);
    /*swap_mem_quick_version(data1, data2, size);*/

    printf("After swapping data\n==================\n");
    printf("Double/Float 1: %f\tDouble/Float 2: %f\n", *(float*)data1, *(float*)data2);
}

void perform_swap_on_int_array(void* data1, void* data2, size_t size)
{
    printf("\nBefore swapping data\n==================\n");
    printf("Array 1:");
    display_array(data1, size);
    printf("Array 2:");
    display_array(data2, size);

    swap_mem(data1, data2, size * sizeof(int));
    /*swap_mem_quick_version(data1, data2, size * sizeof(int));*/

    printf("\nAfter swapping data\n===================\n");
    printf("Array 1:");
    display_array(data1, size);
    printf("Array 2:");
    display_array(data2, size);
}
