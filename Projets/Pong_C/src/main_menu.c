/**
 * @author Mick Cool
 * @file main_menu.c
 * @date 14.01.2022
*/
#include <SDL.h>
/*#include <SDL_ttf.h>*/
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_TITLE "PONG GAME"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define BALL_SIZE 100
#define SPEED 120
#define BLACK {0, 0, 0, 100}
#define WHITE {255, 255, 255, 100}
#define WHITE_CLAIR {250, 250, 250, 80}

typedef struct {
    int x;
    int y;
    float dx;
    float dy;
    int size;
} Ball;

void InitSDL(SDL_Window **window, SDL_Renderer **renderer);
void Update(SDL_Window *window, SDL_Renderer *renderer, Ball *ball, float elapsedTime);
void Update_Ball(Ball *ball, float elapsedTime);
void Ouit_Properly(SDL_Window *window, SDL_Renderer *renderer);
void Change_Render_Color(SDL_Window *window, SDL_Renderer *renderer, SDL_Color color);
int SDL_RenderFillCircle(SDL_Renderer * renderer, int x, int y, int radius);
Ball Create_Ball(int x, int y, float dx, float dy, int size);

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    SDL_Color black = WHITE;
    SDL_Color lineDarkBlue = {55, 55, 255, 10};
    /*SDL_Color lineDarkRed = {255, 55, 55, 80};*/
    SDL_Color lineWhite = {255, 255, 255, 150};
    SDL_Event event;
    SDL_bool quit = SDL_FALSE;
    int lastTime = 0;
    int currentTime = 0;
    float elapsedTime = 0;
    Ball ball = Create_Ball(
        WINDOW_WIDTH/2 - BALL_SIZE/2, 
        WINDOW_HEIGHT/2 - BALL_SIZE/2, 
        SPEED, SPEED, 
        BALL_SIZE
    );

    /*int i = 0;*/

    InitSDL(&window, &renderer);

    lastTime = SDL_GetTicks();

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = SDL_TRUE;
            }
        }

        currentTime = SDL_GetTicks();
        elapsedTime = (currentTime - lastTime) / 1000.0f;
        Update(window, renderer, &ball, elapsedTime);
        lastTime = currentTime;

    }
        

    Ouit_Properly(window, renderer);
    return EXIT_SUCCESS;
}

/* A refaire proprement, je passe dessus rapidement ce soir */
void InitSDL(SDL_Window **window, SDL_Renderer **renderer)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    *window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (*window == NULL) {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        Ouit_Properly(*window, *renderer);
        exit(EXIT_FAILURE);
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (*renderer == NULL) {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        Ouit_Properly(*window, *renderer);
        exit(EXIT_FAILURE);
    }
}

void Update(SDL_Window *window, SDL_Renderer *renderer, Ball *ball, float elapsedTime)
{
    SDL_Rect ballRect = {ball->x, ball->y, ball->size, ball->size};
    SDL_Color colorblack = BLACK;
    SDL_Color colorwhite = WHITE;
    SDL_Color clair_white = WHITE_CLAIR;

    Change_Render_Color(window, renderer, colorblack);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_RenderClear(renderer);

    Update_Ball(ball, elapsedTime);
    Change_Render_Color(window, renderer, colorwhite);
    /*SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);*/
    /*SDL_RenderFillRect(renderer, &ballRect);*/
    SDL_RenderFillCircle(renderer, ball->x, ball->y, ball->size);
    /*SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);*/
    /*SDL_RenderFillCircle(renderer, ball->x, ball->y, ball->size);*/

    /*Change_Render_Color(window, renderer, clair_white);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_RenderFillCircle(renderer, ball->x + 2, ball->y - 1, ball->size);
    SDL_RenderFillCircle(renderer, ball->x + 3, ball->y - 2, ball->size);
    SDL_RenderFillCircle(renderer, ball->x + 4, ball->y - 3, ball->size);*/

    SDL_RenderPresent(renderer);
}

void Update_Ball(Ball *ball, float elapsedTime)
{
    ball->x += ball->dx * elapsedTime;
    ball->y += ball->dy * elapsedTime;
    if (ball->x < 0) {
        ball->dx = SDL_fabs(ball->dx);
    }
    if (ball->x > WINDOW_WIDTH - BALL_SIZE) {
        ball->dx = -SDL_fabs(ball->dx);
    }
    if (ball->y < 0) {
        ball->dy = SDL_fabs(ball->dy);
    }
    if (ball->y > WINDOW_HEIGHT - BALL_SIZE) {
        ball->dy = -SDL_fabs(ball->dy);
    }
}

void Ouit_Properly(SDL_Window *window, SDL_Renderer *renderer)
{
    /* Si la memoire du rendu a ete alloue, detruire le */
    if(renderer != NULL)
        SDL_DestroyRenderer(renderer);

    /* Pareil Ici */
    if(window != NULL)
        SDL_DestroyWindow(window);

    SDL_Quit();
}

void Change_Render_Color(SDL_Window *window, SDL_Renderer *renderer, SDL_Color color)
{
    if(SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) != 0) {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        Ouit_Properly(window, renderer);
        exit(EXIT_FAILURE);
    }
}

Ball Create_Ball(int x, int y, float dx, float dy, int size)
{
    Ball ball;

    ball.x = x;
    ball.y = y;
    ball.dx = dx * -1;
    ball.dy = dy;
    ball.size = size;

    return ball;
}

/* fonction prise en liogne*/
int SDL_RenderFillCircle(SDL_Renderer * renderer, int x, int y, int radius)
{
    int offsetx, offsety, d;
    int status;


    offsetx = 0;
    offsety = radius;
    d = radius -1;
    status = 0;

    while (offsety >= offsetx) {

        status += SDL_RenderDrawLine(renderer, x - offsety, y + offsetx,
                                     x + offsety, y + offsetx);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y + offsety,
                                     x + offsetx, y + offsety);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y - offsety,
                                     x + offsetx, y - offsety);
        status += SDL_RenderDrawLine(renderer, x - offsety, y - offsetx,
                                     x + offsety, y - offsetx);

        if (status < 0) {
            status = -1;
            break;
        }

        if (d >= 2*offsetx) {
            d -= 2*offsetx + 1;
            offsetx +=1;
        }
        else if (d < 2 * (radius - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }

    return status;
}