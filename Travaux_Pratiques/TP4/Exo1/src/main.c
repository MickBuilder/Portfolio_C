#include <stdlib.h>
#include <stdio.h>

#include "include/stack.h"

#define YES "YES"
#define NO  "NO"

int main(int argc, char const *argv[])
{
    stack_init();

    printf("Stack is empty ? %s\n", stack_is_empty() ? YES : NO);

    stack_push(1);
    stack_push(2);
    stack_push(3);
    stack_push(4);
    stack_push(5);

    printf("Stack is empty ? %s\n", stack_is_empty() ? YES : NO);

    stack_display();

    printf("Size of the stack : %d\n", stack_size());

    printf("Poped %d\n", stack_pop());
    printf("Poped %d\n", stack_pop());

    stack_display();

    printf("Size of the stack : %d\n", stack_size());

    printf("Top of the stack : %d\n", stack_pop());

    printf("The elt at index 1 is %d\n", stack_get_element(1));

    return EXIT_SUCCESS;
}
