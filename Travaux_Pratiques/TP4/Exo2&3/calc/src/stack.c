#include <stdio.h>
#include "include/stack.h"

/* This module proposes a single global and static stack */
static Stack stack;

/* Initialize correctly the stack */
void stack_init(void)
{
    stack.size = 0;
}

/* Returns the current size of the stack. */
int stack_size(void) {
    return stack.size;
}

/* Returns 1 if the stack is empty, returns 0 otherwise. */
int stack_is_empty(void) {
    return stack.size == 0;
}

/* Returns the element at the top of the stack. */
int stack_top(void) {
    int size;
    if (stack_is_empty()) {
        return -1;
    }
    size = stack_size();
    return stack.values[size - 1];
}

/* Pops the element at the top of the stack and returns it. */
int stack_pop(void) {
    int top;
    if (stack_is_empty()) {
        return -1;
    }
    top = stack_top();
    stack.size--;
    return top;
}

/* Pushes a given integer `n` at the top of the stack. */
void stack_push(int n) {
    if (stack_size() == MAX_SIZE) {
        return ;
    }
    stack.values[stack_size()] = n;
    stack.size++;
}

/* Displays the content of the stack on the standard output. */
void stack_display(void) {
    int i;

    if (stack_is_empty()) {
        printf("Stack is empty.\n");
    }

    printf("Values in the stack: ");
    for (i = 0; i < stack_size(); i++) {
        printf("%d ", stack.values[i]);
    }
    putchar('\n');
}

/* 
 * Returns the element at index `index` inside the stack. The user is
 * responsible of the use of this function. The answers may be not
 * relevant if a call is done outside the current size of the
 * stack. 
*/
int stack_get_element(int index) {
    if (index >= stack_size()) {
        return -1;
    }
    return stack.values[index];
}