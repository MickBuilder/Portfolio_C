#ifndef __UTILS_FUNCTIONS_
#define __UTILS_FUNCTIONS_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void swap_mem_quick_version(void* z1, void* z2, size_t size);
void swap_mem(void* z1, void* z2, size_t size);

void display_array(int* array, int size);
void perform_swap_on_int(void* data1, void* data2, size_t size);
void perform_swap_on_char(void* data1, void* data2, size_t size);
void perform_swap_on_real(void* data1, void* data2, size_t size);
void perform_swap_on_int_array(void* data1, void* data2, size_t size);

#endif /* __UTILS_FUNCTIONS_ */