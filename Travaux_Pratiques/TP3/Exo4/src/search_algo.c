#include <stdlib.h>
#include <stdio.h>

/**
 * Recherche d'un élément dans un tableau trié
 * @param array Tableau trié
 * @param low Indice de départ
 * @param high Indice de fin
 * @param elt Valeur à rechercher
 * @return Indice de l'élément recherché, -1 si non trouvé
 * /!\ Attention, le tableau doit être trié
 * /!\ Attention, l'indice de départ doit être inférieur à l'indice de fin
*/
int binary_search(int *array, int low, int high, int elt) {
    /*sort_array(array, high+1); /* Trier le tableau avant de faire la recherche */
    if(low <= high) {
        int middle = (high - low) + low / 2;
        if (array[middle] == elt)
            return middle;
        
        if(array[middle] > elt) {
            return binary_search(array, low, (middle-1), elt);
        } else {
            return binary_search(array, (middle+1), high, elt);
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    /* code */
    int tab[] = {1, 2, 5, 8, 11, 15, 19, 22, 50, 80, 99};
    /* int tab2[] = {1, 99, 5, 11, 8, 19, 15, 22, 100, 80, 99}; */
    int length, res, l;

    length = sizeof(tab) / sizeof(int); /* Calcul de la taille du tableau */

    res = binary_search(tab, 0, length-1, 11);

    res == -1 ? 
    (
        printf("L' element ne se trouve pas dans le tableau\n")
    ) : (
        printf("L'element se touve à l'index %d\n", res)
    );

    return EXIT_SUCCESS;
}
