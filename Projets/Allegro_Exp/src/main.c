#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>

void erreur(const char*txt)
{
    ALLEGRO_DISPLAY*d;
    d = al_is_system_installed() ? al_get_current_display() : NULL;
    al_show_native_message_box(d, "Erreur", txt, NULL, NULL, 0);
    exit(EXIT_FAILURE);
}
/*****************************************************************
*****************************************************************/
int main()
{
    ALLEGRO_DISPLAY*display;
    ALLEGRO_KEYBOARD_STATE key;
    ALLEGRO_BITMAP*image;
    int tx, ty, screenx, screeny;

    if (!al_init())
        erreur("al_init()");
    if (!al_install_keyboard())
        erreur("al_install_keyboard()");
    if (!al_init_image_addon())
        erreur("al_init_image_addon()");

    display = al_create_display(800, 600);
    if (!display)
        erreur("al_create_display()");

    screenx = al_get_display_width(display);
    screeny = al_get_display_height(display);

    image = al_load_bitmap("./res/img/sample.bmp");
    if (!image)
        erreur("al_load_bitmap()");

    tx = al_get_bitmap_width(image);
    ty = al_get_bitmap_height(image);



    do{
        al_get_keyboard_state(&key);

        int flags = 0; // pas de permutation
        // autres possibilités :
        // flags=ALLEGRO_FLIP_HORIZONTAL
        // flags=ALLEGRO_FLIP_VERTICAL
        // flags=ALLEGRO_FLIP_HORIZONTAL|ALLEGRO_FLIP_VERTICAL

        if (al_key_down(&key, ALLEGRO_KEY_F1))
            al_draw_bitmap(image, // l'image source
            0, 0,                 // position
            flags);                 // permutation

        // pour les régions
        int sx = rand() % tx;
        int sy = rand() % ty;
        int sw = rand() % (tx - sx);
        int sh = rand() % (ty - sy);
        int dx = rand() % (screenx - sw);
        int dy = rand() % (screeny - sh);

        if (al_key_down(&key, ALLEGRO_KEY_F2)){
            al_draw_bitmap_region(
                image,
                sx, sy, // hg source
                sw, sh, // taille dans source
                dx, dy, // hg destination
                flags); //permutation
        }

        // taille destination pour déformation
        float dw = ((float)rand() / RAND_MAX)*screenx;
        float dh = ((float)rand() / RAND_MAX)*screeny;
        if (al_key_down(&key, ALLEGRO_KEY_F3))
            al_draw_scaled_bitmap(
            image,        // image source
            0, 0,        // coin haut gauche
            tx, ty,        // taille source
            0, 0,        // coin haut gauche destination
            dw,            // taille destination
            dh,
            flags);        // permutation

        if (al_key_down(&key, ALLEGRO_KEY_F4))
            al_draw_rotated_bitmap(
            image,            // image source
            tx / 2, ty / 2,    //pivot source
            screenx / 2,    //pivot destination
            screeny / 2,
            rand() % 360,    // angle en radian
            flags);            // permutation

        // proportion pour déformation
        float xscale = ((float)rand() / RAND_MAX) * 2;
        float yscale = ((float)rand() / RAND_MAX) * 2;
        float angle = ((float)rand() / RAND_MAX)* (2 * 3.14);
        if (al_key_down(&key, ALLEGRO_KEY_F5)){
            al_draw_scaled_rotated_bitmap(
                image,
                tx / 2, ty / 2,    //pivot source
                screenx / 2,    //pivot destination
                screeny / 2,
                xscale, yscale, // le rapport,
                angle,            // angle en radian
                flags);            // permutation
        }

        // pour les affichages teintés
        // la couleur originale de chaque pixel est modifiée
        // par multiplication. Par exemple un filtre de
        // al_map_rgba_f(0.5, 0.5,0.5,0.5)
        // signifie que rouge,vert, bleu et transparence de
        // l'image seront divisés par deux
        // un filtre de al_map_rgba_f(1, 0,0,2) signifie
        // que le rouge reste identique, vert et bleu sont
        // supprimés et transparence multipliée par deux.
        float r = ((float)rand() / RAND_MAX) * 2;
        float g = ((float)rand() / RAND_MAX) * 2;
        float b = ((float)rand() / RAND_MAX) * 2;
        float a = ((float)rand() / RAND_MAX) * 2;
        ALLEGRO_COLOR filtre = al_map_rgba_f(r, g, b, a);

        if (al_key_down(&key, ALLEGRO_KEY_F6))
            al_draw_tinted_bitmap(
            image,
            filtre, // transformation couleur
            0, 0, // position destination
            flags); // permutation


        if (al_key_down(&key, ALLEGRO_KEY_F7))
            al_draw_tinted_bitmap_region(
            image,
            filtre,
            sx, sy, //coin hg source
            sw, sh, // taille source
            dx, dy, // position destination
            flags);// permutations


        if (al_key_down(&key, ALLEGRO_KEY_F8))
            al_draw_tinted_scaled_bitmap(
            image,
            filtre,
            sx, sy,// coin h-g source
            sw, sh,// taille source
            dx, dy,// coin h-g destination
            dw, dh,// taille destination
            flags); // permutation

        if (al_key_down(&key, ALLEGRO_KEY_F9))
            al_draw_tinted_rotated_bitmap(
            image,
            filtre,
            tx / 2, ty / 2, // pivot source
            dx, dy, // pivot destination
            angle,
            flags);

        if (al_key_down(&key, ALLEGRO_KEY_F10))
            al_draw_tinted_scaled_rotated_bitmap(
            image,
            filtre,
            tx / 2, ty / 2,//pivot source
            dx, dy, // pivot destination
            xscale, yscale,// rapport taille
            angle,
            flags);

        if (al_key_down(&key, ALLEGRO_KEY_F11))
            al_draw_tinted_scaled_rotated_bitmap_region(
            image,
            sx, sy,// source h-g
            sw, sh,// source taille
            filtre,
            tx / 2, ty / 2,// pivot source
            dx, dy,// pivot destination
            xscale, yscale, // rapport taille
            angle,
            flags);

        if (al_key_down(&key, ALLEGRO_KEY_ENTER))
            al_clear_to_color(al_map_rgb(0, 0, 0));
        

        al_flip_display();
    } while (!al_key_down(&key, ALLEGRO_KEY_ESCAPE));

    al_destroy_display(display);
    al_destroy_bitmap(image);
    return 0;
}
/*****************************************************************
*****************************************************************/