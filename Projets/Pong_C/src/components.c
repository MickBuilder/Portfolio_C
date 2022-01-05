#include "include/components.h"

actor* init_actor(int x, int y)
{
    actor* a = malloc(sizeof(actor));
    a->x = x;
    a->y = y;

    return a;
}

