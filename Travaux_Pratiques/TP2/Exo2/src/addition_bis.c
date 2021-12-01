#include <stdlib.h>
#include <stdio.h>

/*
 * main - Point d'entree
 * @argc: nombre d'arguments
 * @argv: tableau d'arguments
 * Return: 0
*/
int main (int argc, char *argv[])
{
    int a, b; /* declaration des variables */
    a = b = 0; /* initialisation des variables */

    /* Deuxième version de l'exercice */
    /* verification des arguments */
    if (argc != 3)
    {
        printf("Erreur : nombre d'arguments incorrect\n");
        printf("Usage : %s <nombre a> <nombre b>\n", argv[0]);
        return EXIT_FAILURE;
    }
    /* conversion des arguments en entiers */
    a = atoi(argv[1]);
    b = atoi(argv[2]);

    /* affichage du resultat */
    printf("%d + %d = %d\n", a, b, a + b);
    
    return EXIT_SUCCESS;
}