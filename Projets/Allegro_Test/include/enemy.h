#ifndef __ENEMY_H_
#define __ENEMY_H_
/* Demander au prof?:
 * Pas envie de dupliquer define, comment faire pour acceder à SREEN_.. avec inclusion?  
#include "ship.h"*/

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MAX_ENEMY 10

typedef struct enemy_t
{
    int pos_x, pos_y;
    int speed;
    int width, height;
    bool is_alive;
} Enemy;

void init_enemies(Enemy e[]);

void display_enemies(Enemy e[]);

void move_enemies(Enemy e[]);

void show_random_enemy(Enemy e[]);

#endif /* __ENEMY_H_ */