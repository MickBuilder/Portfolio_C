#ifndef _ARRAY_H_
#define _ARRAY_H_

    int* allocate_integer_array(int size);
    void free_integer_array(int* tab);
    int array_size(int* array);
    void array_print(int* array);
    int are_arrays_equal(int* first, int* second);
    int* array_copy(int* array);
    int* fill_array();
    int* random_array(int size, int max_value);
    int* concatenate_arrays(int* first, int* second);
    int* merge_sorted_arrays(int* first, int* second);
    void split_arrays(int* array, int** first, int** second);
    int* merge_sort(int* array);

#endif /* _ARRAY_H_ */