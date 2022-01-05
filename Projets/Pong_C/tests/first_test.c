#include <stdlib.h>
#include <stdio.h>
#include "test.h"
#include "../src/include/toto.h"

void test_Add() {
    int a = 5, b = 4, expected = 9;
    int res = Add(a, b);
    TEST_CHECK_(res == expected, "Expected : %d \t Produced : %d", expected, res);
}

TEST_LIST = {
    { "Add(a, b) function ==> ", test_Add },
    { NULL, NULL }
};