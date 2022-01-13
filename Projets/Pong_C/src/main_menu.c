#include <SDL.h>
/*#include <SDL_ttf.h>*/
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_TITLE "PONG GAME"
#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

void Ouit_Program_Error(SDL_Window *window, SDL_Renderer *renderer);

int main(int argc, char *argv[])
{
    SDL_Window *window          = NULL;
    SDL_Renderer *renderer      = NULL;
    SDL_Rect middle_line        = {(WINDOW_WIDTH / 2) - 2, 0, 2, WINDOW_HEIGHT};
    SDL_Color lineDarkBlue      = {55, 55, 255, 80};
    SDL_Color lineDarkRed       = {255, 55, 55, 80};
    SDL_Color lineWhite         = {255, 255, 255, 150};
    SDL_Color white	            = {255, 255, 255, 255};
    SDL_Color pauseScreenColor	= {0, 0, 0, 75};
    SDL_Event event; 
    SDL_bool game_loop      = SDL_TRUE;
    int i = 0;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (window == NULL) {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        Ouit_Program_Error(window, renderer);
        return EXIT_FAILURE;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL) {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        Ouit_Program_Error(window, renderer);
        return EXIT_FAILURE;
    }

    SDL_RenderClear(renderer);

    if(SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b, white.a) != 0) {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        Ouit_Program_Error(window, renderer);
        return EXIT_FAILURE;
    }

    if(SDL_SetRenderDrawColor(renderer, lineDarkBlue.r, lineDarkBlue.g, lineDarkBlue.b, lineDarkBlue.a) != 0) {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        Ouit_Program_Error(window, renderer);
        return EXIT_FAILURE;
    }

    for (i = 0; i < 20; i++) {
        SDL_RenderDrawLine(renderer, 0, i * 25, WINDOW_WIDTH/2, i * 25);
    }

    for (i = 0; i < 10; i++) {
        SDL_RenderDrawLine(renderer, i * 25, 0, i * 25, WINDOW_HEIGHT);
    }

    if(SDL_SetRenderDrawColor(renderer, lineDarkRed.r, lineDarkRed.g, lineDarkRed.b, lineDarkRed.a) != 0) {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        Ouit_Program_Error(window, renderer);
        return EXIT_FAILURE;
    }

    for (i = 0; i < 20; i++) {
        SDL_RenderDrawLine(renderer, WINDOW_WIDTH/2, i * 25, WINDOW_WIDTH, i * 25);
    }

    for (i = 0; i < 10; i++) {
        SDL_RenderDrawLine(renderer, WINDOW_WIDTH - i * 25, 0, WINDOW_WIDTH - i * 25, WINDOW_HEIGHT);
    }

    if(SDL_SetRenderDrawColor(renderer, lineWhite.r, lineWhite.g, lineWhite.b, lineWhite.a) != 0) {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        Ouit_Program_Error(window, renderer);
        return EXIT_FAILURE;
    }

    /*SDL_RenderDrawLine(renderer, WINDOW_WIDTH/2, 0, WINDOW_WIDTH/2, WINDOW_HEIGHT);*/
    SDL_RenderDrawRect(renderer, &middle_line);

    SDL_RenderPresent(renderer);

    if(SDL_SetRenderDrawColor(renderer, pauseScreenColor.r, pauseScreenColor.g, pauseScreenColor.b, pauseScreenColor.a) != 0) {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        Ouit_Program_Error(window, renderer);
        return EXIT_FAILURE;
    }
    
    SDL_RenderPresent(renderer);
    
    while(game_loop) {
        SDL_RenderClear(renderer);
        SDL_WaitEvent(&event);

        switch (event.type)
        {
            case SDL_QUIT:
                game_loop = SDL_FALSE;
                break;
            
            case SDL_KEYDOWN:
                printf("Appui sur une touche\n");
                break;

            case SDL_MOUSEBUTTONUP:
                if(event.button.button == SDL_BUTTON_LEFT && event.button.clicks >= 2)
                    printf("Au moins deux clics gauches\n");
                break;

            case SDL_WINDOWEVENT:
                if(event.window.event == SDL_WINDOWEVENT_RESIZED){
                    /* printf("Fenêtre redimensionnée\n"); /* Fenêtre redimensionnée */
                    if(SDL_SetRenderDrawColor(renderer, lineDarkBlue.r, lineDarkBlue.g, lineDarkBlue.b, lineDarkBlue.a) != 0) {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        Ouit_Program_Error(window, renderer);
        return EXIT_FAILURE;
    }

    for (i = 0; i <= 20; i++) {
        SDL_RenderDrawLine(renderer, 0, i * 25, WINDOW_WIDTH/2, i * 25);
    }

    for (i = 0; i <= 10; i++) {
        SDL_RenderDrawLine(renderer, i * 25, 0, i * 25, WINDOW_HEIGHT);
    }

    if(SDL_SetRenderDrawColor(renderer, lineDarkRed.r, lineDarkRed.g, lineDarkRed.b, lineDarkRed.a) != 0) {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        Ouit_Program_Error(window, renderer);
        return EXIT_FAILURE;
    }

    for (i = 0; i <= 20; i++) {
        SDL_RenderDrawLine(renderer, WINDOW_WIDTH/2, i * 25, WINDOW_WIDTH, i * 25);
    }

    for (i = 0; i <= 10; i++) {
        SDL_RenderDrawLine(renderer, WINDOW_WIDTH - i * 25, 0, WINDOW_WIDTH - i * 25, WINDOW_HEIGHT);
    }

    if(SDL_SetRenderDrawColor(renderer, lineWhite.r, lineWhite.g, lineWhite.b, lineWhite.a) != 0) {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        Ouit_Program_Error(window, renderer);
        return EXIT_FAILURE;
    }

    /*SDL_RenderDrawLine(renderer, WINDOW_WIDTH/2, 0, WINDOW_WIDTH/2, WINDOW_HEIGHT);*/
    SDL_RenderDrawRect(renderer, &middle_line);
    if(SDL_SetRenderDrawColor(renderer, pauseScreenColor.r, pauseScreenColor.g, pauseScreenColor.b, pauseScreenColor.a) != 0) {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        Ouit_Program_Error(window, renderer);
        return EXIT_FAILURE;
    }
                    SDL_RenderPresent(renderer);
                }
                break;

            default:
                break;
        }
        
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}

void Ouit_Program_Error(SDL_Window *window, SDL_Renderer *renderer)
{
    /* Si la memoire du rendu a ete alloue, detruire le */
    if(renderer != NULL)
    {
        SDL_DestroyRenderer(renderer);
    }

    /* Pareil Ici */
    if(window != NULL)
    {
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
}

void draw_Grid() {}