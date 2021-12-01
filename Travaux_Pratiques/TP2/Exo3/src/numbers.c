#include <stdlib.h>
#include <stdio.h>
#include "./include/numbers.h"

/* 
 * NB: A partir d'ici, les noms de variables et de fonctions 
 * seront en anglais.  Seul les commentaires seront en
 * francais.
*/

/*
 * iterative_function: Fonction iterative qui affiche les de n n-1 ... 2 1 1 2 ... n-1 n
 * en utilisant la boucle for
 * @param n : borne supérieure
 * Return : void
*/
void iterative_function(int n) 
{
    int i;
    /* Partie decroissante */
    for (i = n; i > 0; i--)
    {   
        printf("%d ", i);
    }
    /* Partie croissante */
    for (i = 1; i <= n; i++)
    {   
        printf("%d ", i);
    }
}

/*
 * recursive_function: Fonction récursive qui affiche les de n n-1 ... 2 1 1 2 ... n-1 n
 * en utilisant la recursivite
 * @param n : borne supérieure
 * Return : void
*/ 
void recursive_function(int n) 
{
    if (n >= 1) 
    {
        printf("%d ", n);
        recursive_function(n - 1);
        printf("%d ", n); /* C'est malin ça, je ne le savais pas (!A revoir pour mieux maitriser ça) */
    }
}

/*
 * main - Point d'entree
 * @argc: nombre d'arguments
 * @argv: tableau d'arguments
 * Return 0
*/

int main(int argc, char const *argv[])
{
    /* Version Iterative de la fonction */
    printf("---------Iterative Version---------\n");
    iterative_function(5);
    /* Retour à la ligne */
    printf("\n");

    /* Version Recursive de la fonction */
    printf("\n---------Recursive Version---------\n");
    recursive_function(5);
    /* Retour à la ligne */
    printf("\n");

    return EXIT_SUCCESS;
}

