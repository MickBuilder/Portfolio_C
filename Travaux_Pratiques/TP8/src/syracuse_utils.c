#include "./inc/utilities.h"

void print_syracuse_of(int number) {
    int res = 0;
    while(res > 1) {
        if(number % 2 == 0) {
            res /= 2;
        } else {
            res = (3 * res) + 1;
        }
    }
}