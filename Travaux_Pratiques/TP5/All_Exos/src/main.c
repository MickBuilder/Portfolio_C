#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/array.h"

#define ARRAY_SIZE 20
#define MAX_VALUE 100

/* An empty main to test the compilation of the allocation and free
   functions. */
int main(int argc, char* argv[]){
    int *rand_array, *sort_array;
    srand(time(NULL)); /* Initialisation de l'aleatoire chaque fois */
    printf("--------Welcome Tester--------\n");
    printf("Now a random array of length %d whose entries are lower than %d : \n",  ARRAY_SIZE, MAX_VALUE);
    rand_array = random_array(ARRAY_SIZE, MAX_VALUE);
    print_array(rand_array);

    /*sleep(5000);*/

    printf("Using a merge sort, we get :\n");
    sort_array = merge_sort(rand_array);

    printf("Here is the sorted array : \n");
    print_array(sort_array);

    return EXIT_SUCCESS;
}