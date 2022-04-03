#ifndef __SHIP_H
#define __SHIP_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

#include "enemy.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MAX_MISSILES 5

/*extern const int SCREEN_WIDTH = 800;
extern const int SCREEN_HEIGHT = 600;*/

typedef struct t_ship
{
    int pos_x, pos_y;
    int speed;
    int width, height;
    int life;
    int score;
    ALLEGRO_BITMAP *image;
} Ship;

typedef struct missile
{
    int pos_x, pos_y;
    int speed;
    bool active;
} Missile;


enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE, KEY_MAX};

void init_ship(Ship *ship);

void display_ship(Ship *ship);

void move_up(Ship *ship);

void move_down(Ship *ship);

void move_left(Ship *ship);

void move_right(Ship *ship);

void collision_detection(Ship *ship, Enemy e[]);


void init_all_missiles(Missile m[]);

void display_missiles(Missile m[]);

void move_missiles(Missile m[]);

void launch_missile(Missile m[], Ship *ship);

void destroy_enemy(Ship *ship, Missile m[], Enemy e[]);


void display_error(char *error_message);

#endif /* __SHIP_H */