#include <stdlib.h>
#include <stdio.h>
#include "../src/include/array.h"
#include "test.h"

void test_allocate_integer_array() {
    int* tab = allocate_integer_array(5);
    TEST_CHECK(tab != NULL);
}

void test_free_integer_array() {
    /* Pas de maniere propre de prouver que le memoire a ete bien libere */
}

void test_array_size() {
    int expected_size = 4;
    int* tab = allocate_integer_array(5);
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    tab[3] = 4;
    tab[4] = -1;
    TEST_CHECK_(array_size(tab) == expected_size, "Produced : %d; Expected : %d ", array_size(tab), expected_size);

    free_integer_array(tab);
}

void test_print_array() {
    int* tab = allocate_integer_array(5);
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    tab[3] = 4;
    tab[4] = -1;
    print_array(tab);

    free_integer_array(tab);
}

void test_are_arrays_equal() {
    int* tab1 = allocate_integer_array(5);
    int* tab2 = allocate_integer_array(5);

    tab1[0] = 1;
    tab1[1] = 2;
    tab1[2] = 3;
    tab1[3] = 4;
    tab1[4] = -1;

    tab2[0] = 1;
    tab2[1] = 2;
    tab2[2] = 3;
    tab2[3] = 4;
    tab2[4] = -1;

    TEST_CHECK_(are_arrays_equal(tab1, tab2) == 1, "Produced : %d; Expected : %d ", are_arrays_equal(tab1, tab2), 1);

    free_integer_array(tab1);
    free_integer_array(tab2);
}

void test_copy_array() {
    int* tab1 = allocate_integer_array(5);
    int* tab2 = NULL;

    tab1[0] = 1;
    tab1[1] = 2;
    tab1[2] = 3;
    tab1[3] = 4;
    tab1[4] = -1;

    tab2 = copy_array(tab1);
    TEST_CHECK_(are_arrays_equal(tab1, tab2) == 1, "Produced : %d; Expected : %d ", are_arrays_equal(tab1, tab2), 1);

    free_integer_array(tab1);
    free_integer_array(tab2);
}

void test_copy_array_with_anormal() {
    int* tab1 = allocate_integer_array(7);
    int* tab2 = NULL;

    tab1[0] = 1;
    tab1[1] = 2;
    tab1[2] = 3;
    tab1[3] = 4;
    tab1[4] = -2;
    tab1[5] = 4;
    tab1[6] = -3;
    tab1[7] = -1;

    tab2 = copy_array(tab1);
    print_array(tab2);
    TEST_CHECK_(are_arrays_equal(tab1, tab2) == 1, "Produced : %d; Expected : %d ", are_arrays_equal(tab1, tab2), 1);

    free_integer_array(tab1);
    free_integer_array(tab2);
}

void test_fill_array() {
    int* tab = NULL;
    tab = fill_array();

    TEST_CHECK_(tab != NULL, "The array is empty!! NOT GOOD!!");

    free_integer_array(tab);
}

void test_random_array() {
    int* tab = NULL;
    tab = random_array(5, 10);

    TEST_CHECK_(tab != NULL, "The array is empty!! NOT GOOD!!");

    free_integer_array(tab);
}

/*void test_copy_array_with_random() {
    int* tab1 = random_array(7, 100);
    int* tab2 = NULL;

    tab2 = copy_array(tab1);

    TEST_CHECK_(are_arrays_equal(tab1, tab2) == 1, "Produced : %d; Expected : %d ", are_arrays_equal(tab1, tab2), 1);

    free_integer_array(tab1);
    free_integer_array(tab2);
}*/

TEST_LIST = {
    { "allocate_integer_array function ==> ", test_allocate_integer_array },
    { "free_integer_array function ==> ", test_free_integer_array },
    { "array_size function ==> ", test_array_size },
    { "are_arrays_equal function ==> ", test_are_arrays_equal },
    { "copy_array function ==> ", test_copy_array },
    { "copy_array function with anormal values ==> ", test_copy_array_with_anormal },
    { "fill_array function normally ==> ", test_fill_array },
    { "random_array function normally ==> ", test_random_array},
    /*{ "copy_array function with random array ==> ", test_copy_array_with_random},*/
    { NULL, NULL }
};