#ifndef PONG_TRY_H
#define PONG_TRY_H

typedef struct {
    float x;
    float y;
} actor;

actor* init_actor(float x, float y);

void move_actor(actor* a, float x, float y);

void destroy_actor(actor* a);

void update_actor(actor* a);

#endif /* PONG_TRY_H */
