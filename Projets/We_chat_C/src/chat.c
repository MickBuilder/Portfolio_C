#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

#define SCREEN_WIDTH  800
#define SCREEN_HEIGTH 600 

void error(const char* text) {
    ALLEGRO_DISPLAY *display;
    display = al_is_system_installed() ? al_get_current_display() : NULL;
    al_show_native_message_box(display, "ERROR", text, NULL, NULL, 0);
    exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[]) {
    ALLEGRO_DISPLAY *display;
    ALLEGRO_KEYBOARD_STATE key;
    ALLEGRO_MOUSE_STATE mouse;

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

    al_set_window_title(display, "Chat");

    

    while(!quit) {
        al_get_keyboard_state(&key);

        al_get_mouse_state(&mouse);

        if(al_key_down(&key, ALLEGRO_KEY_ESCAPE))
            quit = true;
        
        if(al_key_down(&key, ALLEGRO_KEY_ENTER))
            al_clear_to_color(al_map_rgb(rand()%255, rand()%255, rand()%255));

        if(oldx != mouse.x  || oldy != mouse.y) {
            oldx = mouse.x;
            oldy = mouse.y;
            printf("%d-%d\n", mouse.x, mouse.y);
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