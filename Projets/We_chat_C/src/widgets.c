#include "gui_widgets.h"

Button *new_button(int x, int y, int width, int height, bool rounded, char *text, ALLEGRO_COLOR color_text, ALLEGRO_COLOR color_background, ALLEGRO_FONT *font) {
    Button *button = malloc(sizeof(Button));
    button->x = x;
    button->y = y;
    button->rounded = rounded;
    button->width = width;
    button->height = height;
    button->text = text;
    button->font = font;
    button->color_text = color_text;
    button->color_background = color_background;

    return button;
}

void draw_button(Button *button) {
    int round = button->rounded ? DEFAULT_ROUND : 0;
    al_draw_filled_rounded_rectangle(button->x, button->y, button->x + button->width, button->y + button->height, round, round, button->color_background);
    al_draw_text(button->font, button->color_text, button->x + button->width / 2, button->y + button->height / 2 - PADDING_Y, ALLEGRO_ALIGN_CENTRE, button->text);
}

void button_on_click(ALLEGRO_MOUSE_EVENT *mouse_event, Button *button) {
    if (mouse_event->x >= button->x && mouse_event->x <= button->x + button->width && mouse_event->y >= button->y && mouse_event->y <= button->y + button->height) {
        button->click = true;
    }
}

void update_button(Button *button) {

}

void delete_button(Button *button) {
    free(button);    
}

Input *new_input(int x, int y, int width, int height, bool rounded, ALLEGRO_USTR *text, ALLEGRO_COLOR normal_color_text, ALLEGRO_COLOR focus_color_text, ALLEGRO_COLOR color_background, ALLEGRO_COLOR color_border, ALLEGRO_FONT *font) {
    Input *input = malloc(sizeof(Input));
    input->x = x;
    input->y = y;
    input->width = width;
    input->height = height;
    input->rounded = rounded;
    input->text = text;
    input->normal_color_text = normal_color_text;
    input->focus_color_text = focus_color_text;
    input->color_background = color_background;
    input->color_border = color_border;
    input->font = font;

    return input;
}

void draw_input(Input *input) {
    int round = input->rounded ? DEFAULT_ROUND : 0;
    ALLEGRO_STATE old_state;

    al_store_state(&old_state, ALLEGRO_STATE_BLENDER);
    al_draw_filled_rounded_rectangle(input->x, input->y, input->x + input->width, input->y + input->height, round, round, input->color_background);
    al_draw_rounded_rectangle(input->x, input->y, input->x + input->width, input->y + input->height, round, round, input->color_border, 2);

    al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);
    //al_draw_ustr(input->font, input->active ? input->focus_color_text : input->normal_color_text, input->x + PADDING_X, input->y + input->height / 2 - PADDING_Y, ALLEGRO_ALIGN_LEFT, input->text);

    al_draw_ustr(input->font, input->active ? input->focus_color_text : input->normal_color_text, input->x + PADDING_X, input->y + PADDING_Y, ALLEGRO_ALIGN_LEFT, input->text);

    if (input->active) {
        int cursor_x = al_get_ustr_width(input->font, input->text) + input->x + PADDING_X;
        al_draw_line(cursor_x, input->y + PADDING_Y, cursor_x, input->y + input->height - PADDING_Y, input->focus_color_text, 2);
        //al_draw_line(input->x + PADDING_X, input->y + input->height / 2, input->x + input->width - PADDING_X, input->y + input->height / 2, input->color_border, 2);
    }
    
    al_restore_state(&old_state);
}

void input_on_focus(ALLEGRO_MOUSE_EVENT *mouse_event, Input *input) {
    printf("Not focus yet\n");
    if (mouse_event->x >= input->x && mouse_event->x <= input->x + input->width && mouse_event->y >= input->y && mouse_event->y <= input->y + input->height) {
        printf("focus\n");
        input->active = true;
    }
    draw_input(input);
}

void input_on_key_down(ALLEGRO_KEYBOARD_EVENT *keyboard_event, Input *input) {
    int cursor_position = al_ustr_length(input->text);
    if (input->active) {
        switch (keyboard_event->keycode) {
            case ALLEGRO_KEY_LEFT:
                al_ustr_prev(input->text, &cursor_position);
                printf("left\n");
                break;
            case ALLEGRO_KEY_RIGHT:
                al_ustr_next(input->text, &cursor_position);
                break;
            case ALLEGRO_KEY_HOME:
                cursor_position = 0;
                break;
            case ALLEGRO_KEY_END:
                cursor_position = al_ustr_length(input->text);
                break;
            case ALLEGRO_KEY_BACKSPACE:
                if(al_ustr_prev(input->text, &cursor_position))
                    al_ustr_remove_chr(input->text, cursor_position);
                break;
            case ALLEGRO_KEY_DELETE:
                al_ustr_remove_chr(input->text, cursor_position);
                break;
            case ALLEGRO_KEY_ENTER:
                input->active = false;
                break;
            default:
                if (keyboard_event->unichar >= 32) {
                    al_ustr_insert_chr(input->text, cursor_position, keyboard_event->unichar);
                    //al_ustr_next(input->text, &cursor_position);
                    cursor_position += al_utf8_width(keyboard_event->unichar);
                }
                break;
        }

        draw_input(input);
    }
}

void update_input(Input *input) {
    // if (input->active) {
    //     if (al_key_down(&keyboard_state, ALLEGRO_KEY_BACKSPACE)) {
    //         al_ustr_remove_chr(input->text, al_ustr_length(input->text) - 1);
    //     }
    //     if (al_key_down(&keyboard_state, ALLEGRO_KEY_ENTER)) {
    //         input->active = false;
    //     }
    // }

    //input->active = !input->active;
    draw_input(input);
}

void delete_input(Input *input) {
    free(input);
}