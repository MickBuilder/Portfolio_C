/**
 * @file draw.c
 * @author Mick Cool
 * @brief Functions to draw the game (manage the screen)
 * @version 0.1
 * @date 2022-01-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "./include/draw.h"

/* A refaire proprement, je passe dessus rapidement ce soir */
/**
 * @brief Init the necessary SDL components
 * 
 * @param window 
 * @param renderer 
 */
void InitSDL(SDL_Window **window, SDL_Renderer **renderer)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    *window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

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

/**
 * @brief Function to update all the elements of the game
 * 
 * @param window 
 * @param renderer 
 * @param ball 
 * @param p1 
 * @param p2 
 * @param elapsedTime 
 * @param running 
 */
void Update(SDL_Window *window, SDL_Renderer *renderer, Ball *ball, Paddle *p1, Paddle *p2, float elapsedTime, int *running)
{
    SDL_Color colorblack = BLACK;
    SDL_Color colorwhite = WHITE;
    SDL_Color colorred = RED;
    SDL_Color colorblue = BLUE;
    int isPlayer = 1;

    Change_Render_Color(window, renderer, colorblack);
    SDL_RenderClear(renderer);

    Change_Render_Color(window, renderer, colorwhite);

    Update_Ball(ball, elapsedTime, running);
    Render_Ball(window, renderer, ball);

    Check_Collision(ball, p1, p2);

    Update_Paddle(p1, elapsedTime, running, !isPlayer);
    Change_Render_Color(window, renderer, colorred);
    Render_Paddle(window, renderer, p1);

    Update_Paddle(p2, elapsedTime, running, isPlayer);
    Change_Render_Color(window, renderer, colorblue);
    Render_Paddle(window, renderer, p2);
    

    SDL_RenderPresent(renderer);
}

/**
 * @brief Free the memory allocated for the window and renderer and quit the program
 * 
 * @param window 
 * @param renderer 
 */
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

/**
 * @brief Change the rendering color
 * 
 * @param window 
 * @param renderer 
 * @param color 
 */
void Change_Render_Color(SDL_Window *window, SDL_Renderer *renderer, SDL_Color color)
{
    if(SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) != 0) {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        Ouit_Properly(window, renderer);
        exit(EXIT_FAILURE);
    }
}

int CoinFlip() {
    return rand() % 2;
}

/**
 * @brief Update the ball position
 * 
 * @param ball 
 * @param elapsedTime 
 * @param running 
 */
void Update_Ball(Ball *ball, float elapsedTime, int *running)
{
    if (!*running) {
        return;
    }
    
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

/**
 * @brief Render the ball on the screen
 * 
 * @param window The window to render on
 * @param renderer The renderer to use
 * @param ball The ball to render
 */
void Render_Ball(SDL_Window *window, SDL_Renderer *renderer, Ball *ball)
{
    SDL_Rect ballRect = {ball->x, ball->y, ball->size, ball->size};
    SDL_RenderFillRect(renderer, &ballRect);
}

/**
 * @brief Update paddle position
 * 
 * @param paddle 
 * @param elapsedTime 
 * @param running 
 * @param isPlayer 
 */
void Update_Paddle(Paddle *paddle, float elapsedTime, int *running, int isPlayer){
    const Uint8 *keystate = SDL_GetKeyboardState(NULL);

    if (keystate[SDL_SCANCODE_SPACE]) {
        *running = 1;
        printf("Space pressed\n");
    }

    if (!isPlayer) {
        if (keystate[SDL_SCANCODE_S]) {
            paddle->y += PADDLE_SPEED * elapsedTime;
        }
        if (keystate[SDL_SCANCODE_W]) {
            paddle->y -= PADDLE_SPEED * elapsedTime;
        }
    } else {
        if (keystate[SDL_SCANCODE_UP]) {
            paddle->y -= PADDLE_SPEED * elapsedTime;
        }
        if (keystate[SDL_SCANCODE_DOWN]) {
            paddle->y += PADDLE_SPEED * elapsedTime;
        }
    }

    if (paddle->y < 0) {
        paddle->y = 0;
    }
    if (paddle->y > WINDOW_HEIGHT - PADDLE_HEIGHT) {
        paddle->y = WINDOW_HEIGHT - PADDLE_HEIGHT;
    }
}

/**
 * @brief Render_Paddle
 * @param window
 * @param renderer
 * @param paddle
 */
void Render_Paddle(SDL_Window *window, SDL_Renderer *renderer, Paddle *player)
{
    SDL_Rect paddleRect = {player->x, player->y, PADDLE_WIDTH, PADDLE_HEIGHT};
    SDL_RenderFillRect(renderer, &paddleRect);
}

/**
 * @brief Check if the ball has collided with the paddle
 * 
 * @param ball 
 * @param p1 
 * @param p2 
 */
void Check_Collision(Ball *ball, Paddle *p1, Paddle *p2) {
    SDL_Rect ballRect = {ball->x, ball->y, ball->size, ball->size};
    SDL_Rect p1Rect = {p1->x, p1->y, PADDLE_WIDTH, PADDLE_HEIGHT};
    SDL_Rect p2Rect = {p2->x, p2->y, PADDLE_WIDTH, PADDLE_HEIGHT};

    if (SDL_HasIntersection(&ballRect, &p1Rect)) {
        ball->dx = SDL_fabs(ball->dx);
        printf("Collision with p1\n");
    }
    if (SDL_HasIntersection(&ballRect, &p2Rect)) {
        ball->dx = -SDL_fabs(ball->dx);
        printf("Collision with p2\n");
    }
}