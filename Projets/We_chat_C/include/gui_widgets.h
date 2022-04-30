#ifndef __GUI_WIDGETS_H__
#define __GUI_WIDGETS_H__

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define PADDING_X 10
#define PADDING_Y 10
#define DEFAULT_ROUND 3

typedef struct button {
    int x, y, width, height;
    char *text;
    ALLEGRO_COLOR color_text;
    ALLEGRO_COLOR color_background;
    ALLEGRO_FONT *font;
    bool rounded, click;
} Button;

typedef struct input {
    int x, y, width, height;
    ALLEGRO_USTR *text;
    ALLEGRO_COLOR normal_color_text, focus_color_text;
    ALLEGRO_COLOR color_background, color_border;
    ALLEGRO_FONT *font;
    bool rounded, active;
} Input;

Button *new_button(int x, int y, int width, int height, bool rounded, char *text, ALLEGRO_COLOR color_text, ALLEGRO_COLOR color_background, ALLEGRO_FONT *font);

void draw_button(Button *button);

void button_on_click(ALLEGRO_MOUSE_EVENT *mouse_event, Button *button);

void update_button(Button *button);

void delete_button(Button *button);

Input *new_input(int x, int y, int width, int height, bool rounded, ALLEGRO_USTR *text, ALLEGRO_COLOR normal_color_text, ALLEGRO_COLOR focus_color_text, ALLEGRO_COLOR color_background, ALLEGRO_COLOR color_border, ALLEGRO_FONT *font);

void draw_input(Input *input);

void input_on_focus(ALLEGRO_MOUSE_EVENT *mouse_event, Input *input);

void input_on_key_down(ALLEGRO_KEYBOARD_EVENT *keyboard_event, Input *input);

void update_input(Input *input);

void delete_input(Input *input);



#endif /* __GUI_WIDGETS_H__ */