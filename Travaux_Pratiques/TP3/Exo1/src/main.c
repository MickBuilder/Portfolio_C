#include <stdio.h>
#include <stdlib.h>
#include "./include/puissance.h"

/* An empty main to test the compilation of the allocation and free
   functions. */
int main(int argc, char const *argv[])
{
    int a = 258;
    int n = 3;
    printf("Welcome to the power calculator\n");
    printf("--------------------------------\n");
    printf("%d puissance %d = %d (iterative way)\n", a, n, puissance(a, n));
    printf("%d puissance %d = %d (recursive way)\n", a, n, puissance_rec(a, n));
    return EXIT_SUCCESS;
}