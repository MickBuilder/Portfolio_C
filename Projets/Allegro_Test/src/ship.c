#include "ship.h"

/***********************************
 * SHIP FUNCTIONS UTILITIES
 * *********************************/

void init_ship(Ship *ship) {
    ship->pos_x = 20;
    ship->pos_y = SCREEN_WIDTH / 2;
    ship->speed = 5;
    ship->width = 30;
    ship->height = 20;
    ship->life = 3;
    ship->score = 0;

    ship->image = al_create_bitmap(ship->width, ship->height);

    al_set_target_bitmap(ship->image);

    al_draw_filled_triangle(0, 0, 0, ship->height, ship->pos_x, ship->height / 2, al_map_rgb(0, 255, 0));
}

void display_ship(Ship *ship) {
    al_draw_bitmap(ship->image, ship->pos_x, ship->pos_y, 0);
}

void move_up(Ship *ship) {
    ship->pos_y = (ship->pos_y - ship->speed) < 0 ? 0 : ship->pos_y - ship->speed;
}

void move_down(Ship *ship) {
    ship->pos_y = (ship->pos_y + ship->speed) > SCREEN_HEIGHT ? SCREEN_HEIGHT : ship->pos_y + ship->speed;
}

void move_left(Ship *ship) {
    ship->pos_x = (ship->pos_x - ship->speed) < 0 ? 0 : ship->pos_x - ship->speed;
}

void move_right(Ship *ship) {
    ship->pos_x = (ship->pos_x + ship->speed) > SCREEN_WIDTH ? SCREEN_WIDTH : ship->pos_x + ship->speed;
}

void collision_detection(Ship *ship, Enemy e[]) {
    int i;
    for (i = 0; i < MAX_ENEMY; i++) {
        if (e[i].is_alive) {
            if (ship->pos_x + ship->width > (e[i].pos_x - e[i].width) 
            && ship->pos_x < e[i].pos_x 
            && ship->pos_y + ship->height > (e[i].pos_y - e[i].height) 
            && ship->pos_y < e[i].pos_y) {
                ship->life--;
                e[i].is_alive = false;
            }
        }
    }
}

/* ***********************************
 * MISSILE FUNCTIONS UTILITIES
 * ***********************************/

void init_all_missiles(Missile m[]) {
    int i;
    for (i = 0; i < MAX_MISSILES; i++) {
        m[i].pos_x = 0;
        m[i].pos_y = 0;
        m[i].speed = 10;
        m[i].active = false;
    }
}

void display_missiles(Missile m[]) {
    int i;
    for (i = 0; i < MAX_MISSILES; i++)
    {
        if (m[i].active)
        {
            al_draw_filled_ellipse(m[i].pos_x, m[i].pos_y, 3, 2, al_map_rgb(0, 255, 0));
        }
    }
    
}

void move_missiles(Missile m[]) {
    int i;
    for (i = 0; i < MAX_MISSILES; i++)
    {
        if (m[i].active)
        {
            m[i].pos_x += m[i].speed;
            if (m[i].pos_x > SCREEN_WIDTH)
            {
                m[i].active = false;
            }  
        }
    }
    
}

void launch_missile(Missile m[], Ship *ship) {
    int i;
    for (i = 0; i < MAX_MISSILES; i++)
    {
        if (!m[i].active)
        {
            m[i].pos_x = ship->pos_x + ship->width;
            m[i].pos_y = ship->pos_y + ship->height / 2;
            m[i].active = true;
            break;
        }
    }
    
}

void destroy_enemy(Ship *ship, Missile m[], Enemy e[]) {
    int i, j;
    for (j = 0; j < MAX_ENEMY; j++)
    {
        if (e[j].is_alive)
        {
            for (i = 0; i < MAX_MISSILES; i++)
            {
                if (m[i].active 
                && m[i].pos_x > (e[j].pos_x - e[j].width)
                && m[i].pos_y > (e[j].pos_y - e[j].height)
                && m[i].pos_y < (e[j].pos_y + e[j].height))
                {
                    e[j].is_alive = false;
                    m[i].active = false;
                    ship->score++;
                }
            }
        }
    }
    
}

void display_error(char *error_message) {
    ALLEGRO_DISPLAY *display;
    display = al_is_system_installed() ? al_get_current_display() : NULL;
    al_show_native_message_box(display, "Error", error_message, NULL, NULL, 0);
    exit(1);
}