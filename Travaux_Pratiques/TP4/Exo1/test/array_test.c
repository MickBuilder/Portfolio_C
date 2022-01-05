#include <stdlib.h>
#include <stdio.h>
#include "test.h"

void test_allocate_integer_array() {
    int* tab = allocate_integer_array(5);
    TEST_CHECK(tab != NULL);
}

TEST_LIST = {
    { "allocate_integer_array function ==>", test_allocate_integer_array },
    { NULL, NULL }
};