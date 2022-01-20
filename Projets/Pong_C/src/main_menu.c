/**
 * @author Mick Cool
 * @file main_menu.c
 * @date 14.01.2022
*/
#include "./include/draw.h"
#include "./include/components.h"

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
    int running = 0;
    float elapsedTime = 0;

    Ball ball = Create_Ball(WINDOW_WIDTH/2 - BALL_SIZE/2, WINDOW_HEIGHT/2 - BALL_SIZE/2, SPEED, SPEED, BALL_SIZE);

    Paddle paddle1 = Create_Paddle(0, PADDLE_MARGIN, WINDOW_HEIGHT/2 - PADDLE_HEIGHT/2);
    Paddle paddle2 = Create_Paddle(0, WINDOW_WIDTH - PADDLE_MARGIN - PADDLE_WIDTH , WINDOW_HEIGHT/2 - PADDLE_HEIGHT/2);

    /*int i = 0;*/

    srand(time(NULL));

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
        Update(window, renderer, &ball, &paddle1, &paddle2, elapsedTime, &running);
        lastTime = currentTime;
    }

    Ouit_Properly(window, renderer);
    return EXIT_SUCCESS;
}
