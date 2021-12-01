#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
    /* Première version de l'exercice */

    int a, b; /* declaration des variables */
    a = b = 0; /* initialisation des variables */
    
    printf("Entrez un nombre a : ");
    scanf("%d", &a); 
    printf("Entrez un nombre b : ");
    scanf("%d", &b);

    /* affichage du resultat */
    printf("%d + %d = %d\n", a, b, a + b);
    
    return EXIT_SUCCESS;
}