#ifndef PONG_TRY_H
#define PONG_TRY_H

typedef struct {
    int x;
    int y;
    float dx;
    float dy;
    int size;
} Ball;

typedef struct Paddle {
    float x;
    float y;
    int score;
} Paddle;

Ball Create_Ball(int x, int y, int dx, int dy, int size);

Paddle Create_Paddle(int score, int x, int y);

#endif /* PONG_TRY_H */
