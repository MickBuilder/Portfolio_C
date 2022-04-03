#include "enemy.h"

void init_enemies(Enemy e[]) {
    int i;
    for (i = 0; i < MAX_ENEMY; i++) {
        e[i].height = 10 + rand() % 20;
        e[i].width = 10 + rand() % 20;
        e[i].speed = 5 + rand() % 2;
        e[i].is_alive = false;
    }
}

void display_enemies(Enemy e[]) {
    int i;
    for (i = 0; i < MAX_ENEMY; i++) {
        if (e[i].is_alive) {
            al_draw_filled_ellipse(e[i].pos_x, e[i].pos_y, e[i].width, e[i].height, al_map_rgb(255, rand() % 256, rand() % 256));
        }
    }
}

void move_enemies(Enemy e[]) {
    int i;
    for (i = 0; i < MAX_ENEMY; i++) {
        if (e[i].is_alive) {
            e[i].pos_x -= e[i].speed;
            if (e[i].pos_x < 0) {
                e[i].is_alive = false;
            }
        }
    }
}

void show_random_enemy(Enemy e[]) {
    int i;
    for (i = 0; i < MAX_ENEMY; i++) {
        if (!e[i].is_alive && rand() % 100 < 10) {
            e[i].pos_x = SCREEN_WIDTH - e[i].width;
            e[i].pos_y = e[i].height + rand() % (SCREEN_HEIGHT - e[i].height * 2);
            e[i].is_alive = true;
            break;
        }
    }
}