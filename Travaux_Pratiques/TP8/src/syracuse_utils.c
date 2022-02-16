#include <stdlib.h>
#include <stdio.h>
#include "./inc/utilities.h"

#define MAX_NUMBER 200000000

void print_syracuse_of(unsigned long int number) {
    int fly = 0;
    printf("%lu ", number);
    while(number > 1) {
        if(number % 2 == 0) {
            number /= 2;
            fly++;
            printf("%lu ", number);
        } else {
            number = (3 * number) + 1;
            fly++;
            printf("%lu ", number);
        }
    }
    printf("\n");
    printf("Fly Length : %d\n", fly);
}

int get_fly_length(unsigned long int number) {
    int fly = 0;
    while(number > 1) {
        if(number % 2 == 0) {
            number /= 2;
            fly++;
        } else {
            number = (3 * number) + 1;
            fly++;
        }
    }
    return fly;
}

int get_fly_length_memoized(unsigned long int number, unsigned long int *fly_lengths) {    
    int fly;

    /* Lecture */
    if(number < MAX_NUMBER && fly_lengths[number] != -1) {
        return fly_lengths[number];
    }

    /* Calcul */
    if(number == 1) {
        fly = 0;
    } else if(number % 2 == 0) {
        fly = 1 + get_fly_length_memoized(number / 2, fly_lengths);
    } else {
        fly = 1 + get_fly_length_memoized((3 * number) + 1, fly_lengths);
    }

    /* Memoization */

    if (number < MAX_NUMBER) {
        fly_lengths[number] = fly;
        return fly;
    } else {
        return fly;
    }
}

int main(int argc, char const *argv[])
{
    int max_fly = 0;
    /* array */
    static unsigned long int fly_lengths[MAX_NUMBER];
    int i, j;

    /* init */
    for(i = 0; i < MAX_NUMBER; i++) {
        fly_lengths[i] = -1;
    }

    /* */
    for(j = 1; j < MAX_NUMBER; j++) {
        int fly = get_fly_length_memoized(j, fly_lengths);
        if(fly > max_fly) {
            max_fly = fly;
        }
    }

    printf("MAX_FLY : %d\n", max_fly);

    return EXIT_SUCCESS;
}
