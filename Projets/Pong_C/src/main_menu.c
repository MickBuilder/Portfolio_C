/**
 * @author Mick Cool
 * @file main_menu.c
 * @date 14.01.2022
*/
#include <SDL.h>
/*#include <SDL_ttf.h>*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WINDOW_TITLE "PONG GAME"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define BALL_SIZE 100
#define SPEED 120
#define PADDLE_WIDTH 5
#define PADDLE_HEIGHT 80
#define PADDLE_MARGIN 10
#define PADDLE_SPEED 200

#define BLACK {0, 0, 0, 100}
#define WHITE {255, 255, 255, 100}
#define RED {255, 0, 0, 100}
#define BLUE {0, 0, 255, 100}

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

void InitSDL(SDL_Window **window, SDL_Renderer **renderer);
void Update(SDL_Window *window, SDL_Renderer *renderer, Ball *ball, Paddle *p1, Paddle *p2, float elapsedTime, int *running);
void Ouit_Properly(SDL_Window *window, SDL_Renderer *renderer);
void Change_Render_Color(SDL_Window *window, SDL_Renderer *renderer, SDL_Color color);
int CoinFlip();

Ball Create_Ball(int x, int y, int dx, int dy, int size);
void Update_Ball(Ball *ball, float elapsedTime, int *running);
void Render_Ball(SDL_Window *window, SDL_Renderer *renderer, Ball *ball);

Paddle Create_Paddle(int score, int x, int y);
void Update_Paddle(Paddle *paddle, float elapsedTime, int *running, int isPlayer);
void Render_Paddle(SDL_Window *window, SDL_Renderer *renderer, Paddle *paddle);

void Render_Score(SDL_Window *window, SDL_Renderer *renderer, Paddle *p1, Paddle *p2);
void Check_Collision(Ball *ball, Paddle *p1, Paddle *p2);

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

    Ball ball = Create_Ball(
        WINDOW_WIDTH/2 - BALL_SIZE/2, 
        WINDOW_HEIGHT/2 - BALL_SIZE/2, 
        SPEED, SPEED, 
        BALL_SIZE
    );

    Paddle paddle1 = Create_Paddle(0, PADDLE_MARGIN, WINDOW_HEIGHT/2 - PADDLE_HEIGHT/2);
    Paddle paddle2 = Create_Paddle(0, WINDOW_WIDTH - PADDLE_WIDTH - PADDLE_MARGIN, WINDOW_HEIGHT/2 - PADDLE_HEIGHT/2);

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

int CoinFlip() {
    return rand() % 2;
}

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

void Render_Ball(SDL_Window *window, SDL_Renderer *renderer, Ball *ball)
{
    SDL_Rect ballRect = {ball->x, ball->y, ball->size, ball->size};
    SDL_RenderFillRect(renderer, &ballRect);
}

Paddle Create_Paddle(int score, int x, int y) {
    Paddle paddle;
    paddle.x = x;
    paddle.y = y;
    paddle.score = score;
    return paddle;
}

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

    /*if (keystate[SDL_SCANCODE_UP]) {
        paddle->y -= PADDLE_SPEED * elapsedTime;
        printf("UP\n");
    }
    if (keystate[SDL_SCANCODE_DOWN]) {
        paddle->y += PADDLE_SPEED * elapsedTime;
        printf("DOWN\n");
    }*/
    if (paddle->y < 0) {
        paddle->y = 0;
    }
    if (paddle->y > WINDOW_HEIGHT - PADDLE_HEIGHT) {
        paddle->y = WINDOW_HEIGHT - PADDLE_HEIGHT;
    }
}

void Render_Paddle(SDL_Window *window, SDL_Renderer *renderer, Paddle *player)
{
    SDL_Rect paddleRect = {player->x, player->y, PADDLE_WIDTH, PADDLE_HEIGHT};
    SDL_RenderFillRect(renderer, &paddleRect);
}

void Check_Collision(Ball *ball, Paddle *p1, Paddle *p2) {
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
    }*/
    SDL_Rect ballRect = {ball->x, ball->y, ball->size, ball->size};
    SDL_Rect p1Rect = {p1->x, p1->y, PADDLE_WIDTH, PADDLE_HEIGHT};
    SDL_Rect p2Rect = {p2->x, p2->y, PADDLE_WIDTH, PADDLE_HEIGHT};

    if (SDL_HasIntersection(&ballRect, &p1Rect)) {
        ball->dx = -SDL_fabs(ball->dx);
    }
    if (SDL_HasIntersection(&ballRect, &p2Rect)) {
        ball->dx = SDL_fabs(ball->dx);
    }
}