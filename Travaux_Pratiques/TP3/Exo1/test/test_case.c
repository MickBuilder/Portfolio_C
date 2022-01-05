#include <stdlib.h>
#include <stdio.h>
#include "../src/include/puissance.h"
#include "test.h"

void test_puissance_iterative_with_zero()
{
    int a = 258, expected = 1;
    unsigned int n = 0;
    int res = puissance(a, n);
    TEST_CHECK_(res == expected, "Expected : %d \t Produced : %d", expected, res);
}

void test_puissance_iterative()
{
    int a = 3, expected = 81;
    unsigned int n = 4;
    int res = puissance(a, n);
    TEST_CHECK_(res == expected, "Expected : %d \t Produced : %d", expected, res);
}

void test_puissance_recursive_with_zero()
{
    int a = 258, expected = 1;
    unsigned int n = 0;
    int res = puissance_rec(a, n);
    TEST_CHECK_(res == expected, "Expected : %d \t Produced : %d", expected, res);
}

void test_puissance_recursive()
{
    int a = 5, expected = 625;
    unsigned int n = 4;
    int res = puissance_rec(a, n);
    TEST_CHECK_(res == expected, "Expected : %d \t Produced : %d", expected, res);
}


TEST_LIST = {
    { "puissance(a, 0) function ==> ", test_puissance_iterative_with_zero },
    { "puissance(a, n) function ==> ", test_puissance_iterative },
    { "puissance_rec(a, 0) function ==> ", test_puissance_recursive_with_zero },
    { "puissance_rec(a, n) function ==> ", test_puissance_recursive },
    { NULL, NULL }
};