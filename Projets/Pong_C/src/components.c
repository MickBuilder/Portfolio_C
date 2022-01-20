#include "./include/components.h"

Ball Create_Ball(int x, int y, int dx, int dy, int size)
{
    Ball ball;
    int flip_x = CoinFlip() ? 1 : -1;
    int flip_y = CoinFlip() ? 1 : -1;

    ball.x = x;
    ball.y = y;
    ball.dx = dx * flip_x;
    ball.dy = dy * flip_y;
    ball.size = size;

    return ball;
}

Paddle Create_Paddle(int score, int x, int y) {
    Paddle paddle;
    paddle.x = x;
    paddle.y = y;
    paddle.score = score;
    return paddle;
}