#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "gui_widgets.h"

#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600 
#define MAX_CLIENTS 10
#define PADDING_X 10
#define PADDING_Y 10

#define NORMAL al_map_rgb(200, 200, 200)
#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)
#define RED al_map_rgb(255, 0, 0)
#define GREEN al_map_rgb(0, 255, 0)
#define BLUE al_map_rgb(0, 0, 255)
#define YELLOW al_map_rgb(255, 255, 0)

bool focus = false;

typedef struct client {
    int id;
    char *name;
    bool online;
} Client;

void error(const char* text) {
    ALLEGRO_DISPLAY *display;
    display = al_is_system_installed() ? al_get_current_display() : NULL;
    al_show_native_message_box(display, "ERROR", text, NULL, NULL, 0);
    exit(EXIT_FAILURE);
}

ALLEGRO_DISPLAY *allegro_init(ALLEGRO_EVENT_QUEUE **queue, ALLEGRO_TIMER **timer, ALLEGRO_FONT **font, ALLEGRO_TEXTLOG **log) {
    ALLEGRO_DISPLAY *display = NULL;

    /* Initialisation of ..  */
    if (!al_init()) 
        error("Error while initialing the system");

    if(!al_install_keyboard()) 
        error("Error while installing the keyboard");

    if(!al_install_mouse())
        error("Error while installing the mouse");

    if (!al_init_primitives_addon())
        error("Error while initializing primitives addon");

    if (!al_init_font_addon())
        error("Error while initializing font addon");

    if (!al_init_ttf_addon())
        error("Error while initializing ttf addon");

    
    display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    if(!display) {
        error("Error while creating the window");
    }

    *queue = al_create_event_queue();
    if(!*queue) {
        error("Error while creating the event queue");
    }

    *timer = al_create_timer(1.0 / 60);
    if(!*timer) {
        error("Error while creating the timer");
    }

    *log = al_open_native_text_log("Chat Log", 0);
    if(!*log) {
        error("Error while creating the console log");
    }

    /* Registering the event sources */
    al_register_event_source(*queue, al_get_display_event_source(display));
    al_register_event_source(*queue, al_get_keyboard_event_source());
    al_register_event_source(*queue, al_get_mouse_event_source());
    al_register_event_source(*queue, al_get_timer_event_source(*timer));


    al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);
    al_set_window_title(display, "Chat"); /* Set the window title */
    
    *font = al_load_ttf_font("./res/fonts/roboto.ttf", 20, 0);
    if (!*font) {
        error("Error while loading the font");
    }    

    al_start_timer(*timer);

    return display;
}

void allegro_end(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *queue, ALLEGRO_TIMER *timer, ALLEGRO_FONT *font, ALLEGRO_TEXTLOG *log) {
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_font(font);
    al_close_native_text_log(log);
}

bool is_key_pressed(ALLEGRO_KEYBOARD_STATE *key, int keycode, int repeat) {
    static int press[ALLEGRO_KEY_MAX] = {0};
    bool res = false;
    if (al_key_down(key, keycode) && press[keycode] < repeat) {
        press[keycode]++;
        res = true;
    } else if (!al_key_down(key, keycode)) {
        press[keycode] = 0;
    }
    
    return res;
}

void text_entry(ALLEGRO_FONT *font, ALLEGRO_COLOR color, int x, int y, int max_len, bool *state, ALLEGRO_USTR *text) {
    int cursor = 0;
    al_draw_filled_rectangle(x, y, x + 400, y + 50, color);
    al_draw_ustr(font, focus ? color : NORMAL, x, y, ALLEGRO_ALIGN_CENTRE, text);

    if(focus) {
        al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);
        al_draw_line(x + cursor, y, x + cursor, y + 50, RED, 2);
    }
}

void text_entry_on_key_down(ALLEGRO_KEYBOARD_EVENT *event, bool *state, ALLEGRO_USTR **text) {
    int cursor = 0;

    switch(event->keycode) {
        case ALLEGRO_KEY_BACKSPACE:
            if (al_ustr_prev(*text, &cursor)) {
                al_ustr_remove_chr(*text, cursor);
            }
            break;
        case ALLEGRO_KEY_DELETE:
            al_ustr_remove_chr(*text, cursor);
            break;
        case ALLEGRO_KEY_RIGHT:
            al_ustr_next(*text, &cursor);
            break;
        case ALLEGRO_KEY_LEFT:
            al_ustr_prev(*text, &cursor);
            break;
        default:
            if (event->unichar >= 32) {
                al_ustr_insert_chr(*text, cursor, event->unichar);
                cursor += al_utf8_width(event->unichar);
            }
            break;
    }
}

void button_on_mouse_down(ALLEGRO_MOUSE_EVENT *event, Button *button) {
    if (event->x >= button->x && event->x <= button->x + button->width && event->y >= button->y && event->y <= button->y + button->height) {
        button->color_text = RED;
    }
}

int main(int argc, char const *argv[]) {
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_TEXTLOG *console_log;
    ALLEGRO_FONT *font;
    ALLEGRO_USTR *text;

    bool quit = false;
    bool redraw = false;

    srand(time(NULL));

    display = allegro_init(&event_queue, &timer, &font, &console_log);

    Button* send = new_button(
        SCREEN_WIDTH - 100 - PADDING_X,
        SCREEN_HEIGHT - 50 - PADDING_Y,
        100, 50, true, "Send ⤴✔💌", 
        BLUE, WHITE, font
    );

    Input *input = new_input(
        PADDING_X, SCREEN_HEIGHT - 50 - PADDING_Y,
        SCREEN_WIDTH - (100 - PADDING_X) * 2, 50, false, al_ustr_new("placeholder"),
        NORMAL, BLACK, WHITE, BLUE, font
    );

    text = al_ustr_new("Hello World Toto");
    //al_store_state(&old_state, ALLEGRO_STATE_BLENDER);

    text_entry(font, WHITE, 50, 100, 20, &quit, text);

    draw_button(send);
    draw_input(input);

    while(!quit) {
        ALLEGRO_EVENT event;

        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            quit = true;
        if (event.type == ALLEGRO_EVENT_KEY_CHAR) {
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                quit = true;
            else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                focus = !focus;
            } else {
                input_on_key_down(&event.keyboard, input);
            }
        }

        /*if(console_log != NULL && (oldx != mouse.x  || oldy != mouse.y)) {
            oldx = mouse.x;
            oldy = mouse.y;
            al_append_native_text_log(console_log, "Mouse moved to %d-%d\n", mouse.x, mouse.y);
        }*/


        if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            if (event.mouse.button == 1) {
                input_on_focus(&event.mouse, input);
                //button_on_mouse_down(&event.mouse, send);
            }
        }

        if(event.type == ALLEGRO_EVENT_TIMER)
            redraw = true;

        if (redraw && al_is_event_queue_empty(event_queue)) {
            redraw = false;

            /*draw_button(send);
            update_input(input);*/

            al_flip_display();
        }
        
        //al_flip_display();
    }

    allegro_end(display, event_queue, timer, font, console_log);

    return 0;
}