#ifndef DRAW_H
#define DRAW_H

#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "components.h"

#define WINDOW_TITLE "PONG GAME"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define BALL_SIZE 10
#define SPEED 120
#define PADDLE_WIDTH 10
#define PADDLE_HEIGHT 80
#define PADDLE_MARGIN 10
#define PADDLE_SPEED 200

#define BLACK {0, 0, 0, 100}
#define WHITE {255, 255, 255, 80}
#define RED {255, 0, 0, 100}
#define BLUE {0, 0, 255, 100}

void InitSDL(SDL_Window **window, SDL_Renderer **renderer);
void Update(SDL_Window *window, SDL_Renderer *renderer, Ball *ball, Paddle *p1, Paddle *p2, float elapsedTime, int *running);
void Ouit_Properly(SDL_Window *window, SDL_Renderer *renderer);
void Change_Render_Color(SDL_Window *window, SDL_Renderer *renderer, SDL_Color color);
int CoinFlip();

void Update_Ball(Ball *ball, float elapsedTime, int *running);
void Render_Ball(SDL_Window *window, SDL_Renderer *renderer, Ball *ball);

void Update_Paddle(Paddle *paddle, float elapsedTime, int *running, int isPlayer);
void Render_Paddle(SDL_Window *window, SDL_Renderer *renderer, Paddle *paddle);

void Render_Score(SDL_Window *window, SDL_Renderer *renderer, Paddle *p1, Paddle *p2);
void Check_Collision(Ball *ball, Paddle *p1, Paddle *p2);

#endif /* DRAW_H */
