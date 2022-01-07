#include <SDL.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    SDL_version compiled;
    SDL_Window *window = NULL;
    SDL_VERSION(&compiled);

    printf("Compiled with SDL %d.%d.%d\n", compiled.major, compiled.minor, compiled.patch);
    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        return -1;
    }
    window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              500, 500, SDL_WINDOW_SHOWN);
    if(NULL == window)
        fprintf(stderr, "Erreur de creation de la fenetre : %s\n", SDL_GetError());
    else
    {
        SDL_Delay(500);
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
    return EXIT_SUCCESS;
}
