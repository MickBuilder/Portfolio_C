#include "ship.h"
#include "enemy.h"

#define EXIT_SUCESS 0
#define EXIT_FAILURE 1

int main(int argc, char const *argv[])
{
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    bool key[KEY_MAX] = {false};
    bool redraw = false;
    bool game_over = false;

    Ship main_ship;
    Missile missiles[MAX_MISSILES];
    Enemy enemies[MAX_ENEMY];

    srand(time(NULL));

    if (!al_init()) {
        display_error("failed to initialize allegro!");
    }

    if (!al_init_primitives_addon()) {
        display_error("failed to initialize primitives!");
    }
    
    if (!al_install_keyboard()) { /* To use the keyboard */
        display_error("failed to initialize the keyboard!");
    }

    display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!display) {
        display_error("failed to create a screen!");
    }

    event_queue = al_create_event_queue();
    if (!event_queue) {
        display_error("failed to create event queue!");
    }

    timer = al_create_timer(1.0 / 60);
    if (!timer) {
        display_error("failed to create timer!");
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    al_start_timer(timer);

    init_ship(&main_ship);
    al_set_target_backbuffer(display);

    init_all_missiles(missiles);
    init_enemies(enemies);

    while (!game_over)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            game_over = true;
        } else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (ev.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    key[UP] = true;
                    break;
                case ALLEGRO_KEY_DOWN:
                    key[DOWN] = true;
                    break;
                case ALLEGRO_KEY_LEFT:
                    key[LEFT] = true;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    key[RIGHT] = true;
                    break;
                case ALLEGRO_KEY_SPACE:
                    launch_missile(missiles, &main_ship);
                    break;
            }
        } else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
            switch (ev.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    key[UP] = false;
                    break;
                case ALLEGRO_KEY_DOWN:
                    key[DOWN] = false;
                    break;
                case ALLEGRO_KEY_LEFT:
                    key[LEFT] = false;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    key[RIGHT] = false;
                    break;
                case ALLEGRO_KEY_SPACE:
                    key[SPACE] = false;
                    break;
            }
        } else if (ev.type == ALLEGRO_EVENT_TIMER) {
            if (key[UP]) {
                move_up(&main_ship);
            }

            if (key[DOWN]) {
                move_down(&main_ship);
            }

            if (key[LEFT]) {
                move_left(&main_ship);
            }

            if (key[RIGHT]) {
                move_right(&main_ship);
            }

            move_missiles(missiles);

            show_random_enemy(enemies);
            move_enemies(enemies);

            destroy_enemy(&main_ship, missiles, enemies);
            collision_detection(&main_ship, enemies);

            redraw = true;
        }
    

        if (redraw && al_is_event_queue_empty(event_queue)) {
            al_clear_to_color(al_map_rgb(0, 0, 0));

            display_ship(&main_ship);
            display_missiles(missiles);
            display_enemies(enemies);

            al_flip_display();

            redraw = false;
        }
    }

    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    al_destroy_timer(timer);

    return EXIT_SUCESS;
}
