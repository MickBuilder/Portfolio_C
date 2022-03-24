#include <stdlib.h>
#include <stdio.h>
/**
 * Objectif: comprend malloc et free
 * @author Mick Cool
*/

void print_info_zone(void *addr) {
    size_t* info_adr = (size_t*) addr;
    /* Affichage de l'adresse hexadecimale de la zone */
    printf("===================================\n");
    printf("Zone à l'adressage : %p\n", addr);
    /* Affichage d'une taille juste avant la zone */
    printf("%lu\n", info_adr[-1]);
    /* Affichage d'une taille deux cases avant la zone */
    printf("%lu\n", info_adr[-2]);
}


int main(int argc, char const *argv[])
{
    int* tab = (int*)malloc(sizeof(int) * 15); /* tab[15] */
    print_info_zone(tab);
    /*free(tab);*/
    print_info_zone(tab);
    return EXIT_SUCCESS;
}
