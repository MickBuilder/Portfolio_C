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
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
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

/*int
SDL_RenderFillCircle(SDL_Renderer * renderer, int x, int y, int radius)
{
    int offsetx, offsety, d;
    int status;

    /*CHECK_RENDERER_MAGIC(renderer, -1);*

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
}*/

/* Remarque du prof : Le prf m'a aider à créer cette fonction */
int SDL_RenderFillCircle(SDL_Renderer * renderer, int x, int y, int radius) 
{
    int d, status, h;
    status = 0;
    h = radius * 2;
    for (d = 0; d < radius; d++)
    {
        status += SDL_RenderDrawLine(renderer, x + d, y - h/2, x + d, y + h/2);
        status += SDL_RenderDrawLine(renderer, x - d - 1, y - h/2, x - d - 1, y + h/2);
        h--;
    }
    return status;
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
    /*SDL_Rect ballRect = {ball->x, ball->y, ball->size, ball->size};*/
    int res = SDL_RenderFillCircle(renderer, ball->x, ball->y, ball->size);
    /*SDL_RenderFillRect(renderer, &ballRect);*/
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
    SDL_Event event;

    if (keystate[SDL_SCANCODE_SPACE]) {
        *running = 1;
        printf("Run : %d\n", *running);
    }

    /*while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_SPACE)
            {
                *running = !(*running);
                printf("Run : %d\n", *running);
            }
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                printf("normalement quitter : %d\n", *running);
            }
        }
    }*/

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
    }
    if (SDL_HasIntersection(&ballRect, &p2Rect)) {
        ball->dx = -SDL_fabs(ball->dx);
    }
}

/*void Check_Collision(Ball *ball, Paddle *p1, Paddle *p2) {
    /*if (ball->x < 0) {
        if (ball->y > p2->y && ball->y < p2->y + PADDLE_HEIGHT) {
            ball->dx = -SDL_fabs(ball->dx);
        } else {
            p1->score++;
            ball->x = WINDOW_WIDTH / 2 - BALL_SIZE / 2;
            ball->y = WINDOW_HEIGHT / 2 - BALL_SIZE / 2;
            ball->dx = SPEED;
            ball->dy = SPEED;
        }
    }
    if (ball->x > WINDOW_WIDTH - BALL_SIZE) {
        if (ball->y > p1->y && ball->y < p1->y + PADDLE_HEIGHT) {
            ball->dx = SDL_fabs(ball->dx);
        } else {
            p2->score++;
            ball->x = WINDOW_WIDTH / 2 - BALL_SIZE / 2;
            ball->y = WINDOW_HEIGHT / 2 - BALL_SIZE / 2;
            ball->dx = SPEED;
            ball->dy = SPEED;
        }
            if((ball->x <= p1->x + PADDLE_WIDTH) && (ball->y <= p1->y + PADDLE_HEIGHT) && (ball->y >= p1->y)) {
        ball->dx = SDL_fabs(ball->dx);
        printf("Collision with p1\n");
    }

    if((ball->x + BALL_SIZE >= p2->x) && (ball->y <= p2->y + PADDLE_HEIGHT) && (ball->y >= p2->y)) {
        ball->dx = -SDL_fabs(ball->dx);
        printf("Collision with p2\n");
    }
    }*
    SDL_Rect ballRect = {ball->x, ball->y, ball->size, ball->size};
    SDL_Rect p1Rect = {p1->x, p1->y, PADDLE_WIDTH, PADDLE_HEIGHT};
    SDL_Rect p2Rect = {p2->x, p2->y, PADDLE_WIDTH, PADDLE_HEIGHT};

    if (SDL_HasIntersection(&p1Rect, &ballRect)) {
        ball->dx = -SDL_fabs(ball->dx);
    }
    if (SDL_HasIntersection(&p2Rect, &ballRect)) {
        ball->dx = SDL_fabs(ball->dx);
    }
}*/