#include <stdlib.h>
#include <stdio.h>
#include "include/stack.h"

int main(int argc, char const *argv[])
{
    stack_init();
    stack_push(1);
    stack_push(2);
    stack_push(3);
    stack_push(4);
    stack_push(5);
    stack_display();
    printf("Poped %d\n", stack_pop());
    printf("Poped %d\n", stack_pop());
    stack_display();

    return EXIT_SUCCESS;
}
