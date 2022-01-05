/**
 * @author Mick Cool
 * @version 0.0.1
 * @date 02-12-2021
 * @file puissance.c
 * @brief Programme qui affiche la puissance d'un nombre
 * @details Programme qui affiche la puissance d'un nombre
 * @see puissance.h
*/

#include <stdlib.h>
#include <stdio.h>
#include "./include/puissance.h"

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
    if(n == 0) return 1;
    return a * puissance_rec(a, n - 1);
}
