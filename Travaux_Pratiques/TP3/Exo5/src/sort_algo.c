#include <stdlib.h>
#include <stdio.h>

/**
 * sort_array - trie un tableau d'entiers
 * @array: tableau d'entiers
 * @length: taille du tableau
 * Return: void
*/
void sort_array(int *array, int length) {
    int i, j, tmp;
    for(i = 0; i < length; i++) {
        for(j = i; j < length; j++) {
            if (array[j] > array[j+1])
            {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }   
        }
    }
}


int main(int argc, char const *argv[])
{
    /* code */
    int tab[] = {1, 99, 5, 11, 8, 19, 15, 22, 100, 80, 99};
    int length, l;

    length = sizeof(tab) / sizeof(int); /* Calcul de la taille du tableau */

    printf("Le tableau avant tri est : ");
    for(l = 0; l < length; l++) {
        printf("%d ", tab[l]);
    }
    printf("\n");

    sort_array(tab, length);

    printf("Le tableau après tri est : ");
    for(l = 0; l < length; l++) {
        printf("%d ", tab[l]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
