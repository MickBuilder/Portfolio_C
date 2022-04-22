#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define SCREEN_WIDTH  800
#define SCREEN_HEIGTH 600 

#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)

void error(const char* text) {
    ALLEGRO_DISPLAY *display;
    display = al_is_system_installed() ? al_get_current_display() : NULL;
    al_show_native_message_box(display, "ERROR", text, NULL, NULL, 0);
    exit(EXIT_FAILURE);
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

int main(int argc, char const *argv[]) {
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_KEYBOARD_STATE key;
    ALLEGRO_MOUSE_STATE mouse;
    ALLEGRO_TEXTLOG *console_log;
    ALLEGRO_FONT *font;

    int oldx = 0, oldy = 0;
    bool quit = false;

    srand(time(NULL));

    if (!al_init()) {
        error("Error while initialing the system");
    }

    if(!al_install_keyboard()) {
        error("Error while installing the keyboard");
    }

    if(!al_install_mouse()) {
        error("Error while installing the mouse");
    }

    al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);
    
    display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGTH);
    if(!display) {
        error("Error while creating the window");
    }

    al_set_window_title(display, "Chat"); /* Set the window title */

    console_log = al_open_native_text_log("Chat Log", 0);
    if(!console_log) {
        error("Error while creating the console log");
    }

    al_init_font_addon();
    if (!al_init_ttf_addon()) {
        error("Error while initializing the ttf addon");
    }
    
    font = al_load_ttf_font("./res/fonts/roboto.ttf", 40, 0);
    if (!font) {
        error("Error while loading the font");
    }

    while(!quit) {
        al_get_keyboard_state(&key);

        al_get_mouse_state(&mouse);

        /*if(al_key_down(&key, ALLEGRO_KEY_ESCAPE)) {
            quit = true; 
        }*/

        if (is_key_pressed(&key, ALLEGRO_KEY_ESCAPE, 1)) {
            quit = true; 
        }
        
        if (is_key_pressed(&key, ALLEGRO_KEY_SPACE, 1)) {
            al_clear_to_color(WHITE);
            al_draw_textf(font, BLACK, SCREEN_WIDTH/2, 10, ALLEGRO_ALIGN_CENTRE, "Hello World!");
        }

        /*if(al_key_down(&key, ALLEGRO_KEY_ENTER)) {
            al_clear_to_color(al_map_rgb(rand()%255, rand()%255, rand()%255)); 
        }*/

        if (is_key_pressed(&key, ALLEGRO_KEY_ENTER, 1)) {
            al_clear_to_color(al_map_rgb(rand()%255, rand()%255, rand()%255)); 
        }
        

        if(console_log != NULL && (oldx != mouse.x  || oldy != mouse.y)) {
            oldx = mouse.x;
            oldy = mouse.y;
            al_append_native_text_log(console_log, "Mouse moved to %d-%d\n", mouse.x, mouse.y);
        }

        if(mouse.buttons & 1)
            al_clear_to_color(al_map_rgb(rand()%255, rand()%255, rand()%255));

        if(mouse.buttons & 2)
            quit = true;

        al_flip_display();
    }

    al_destroy_display(display);

    return 0;
}