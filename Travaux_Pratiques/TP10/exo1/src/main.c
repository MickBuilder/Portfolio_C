#include "utils_functions.h"

int main(int argc, char const *argv[])
{
    int one = 1, five = 5;
    /* Test on char */
    char char_a = 'a', char_b = 'b';
    /* Test on double */
    double d_two = 2.0, d_three = 3.0;
    /* Test on float */
    float f_two = 2.0, f_three = 3.0;
    /* Test on long */
    /*long l_two = 2L, l_three = 3L;*/
    /* Test on array */
    int first_tab[3] = {1, 2, 3}, second_tab[3] = {4, 5, 6};

    /*printf("%d %d\n", one, five);
    swap_mem(&one, &five, sizeof(int));
    printf("%d %d\n", one, five);

    printf("%c %c\n", char_a, char_b);
    swap_mem(&char_a, &char_b, sizeof(char));
    printf("%c %c\n", char_a, char_b);*/

    perform_swap_on_int(&one, &five, sizeof(int));
    perform_swap_on_char(&char_a, &char_b, sizeof(char));
    perform_swap_on_real(&d_two, &d_three, sizeof(double));
    perform_swap_on_real(&f_two, &f_three, sizeof(float));
    perform_swap_on_int_array(first_tab, second_tab, 3);

    return EXIT_SUCCESS;
}
