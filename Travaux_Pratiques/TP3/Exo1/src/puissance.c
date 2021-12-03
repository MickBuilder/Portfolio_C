/**
 * @author Mick Cool
 * @version 0.0.1
 * @since 02/12/2021
 * @file puissance.c
 * @brief Programme qui affiche la puissance d'un nombre
 * @details Programme qui affiche la puissance d'un nombre
 * @see puissance.h
*/

#include <stdlib.h>
#include <stdio.h>

/**
 * puissance : calcul de la puissance d'un nombre
 * @a : nombre
 * @n : puissance
 * @return : resultat
*/ 
int puissance(int a, unsigned int n) 
{
    int res = 1;
    while (n != 0) {
        res *= a;
        n--;
    }
    return res;
}

/**
 * puissance_rec : calcul de la puissance d'un nombre de manière recursive
 * @a : nombre
 * @n : puissance
 * @return : resultat du calcul
*/
int puissance_rec(int a, unsigned int n)
{
    /* Fonction simple mais puissante */
    if(n == 1) return a;
    return a * puissance_rec(a, n - 1);
}

/**
 * main - Point d'entree
 * @argc: nombre d'arguments
 * @argv: tableau d'arguments
 * @return EXIT_SUCCESS
*/
int main(int argc, char const *argv[])
{
    int a = 258;
    int n = 3;
    printf("Welcome to the power calculator\n");
    printf("--------------------------------\n");
    printf("%d puissance %d = %d (iterative way)\n", a, n, puissance(a, n));
    printf("%d puissance %d = %d (recursive way)\n", a, n, puissance_rec(a, n));
    return EXIT_SUCCESS;
}
