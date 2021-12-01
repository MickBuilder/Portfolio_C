#include <stdlib.h>
#include <stdio.h>

/* Fonction pour afficher un entier */
void print_var(int n) {
    printf("Value of the variable : %d\n", n) ;
}

/* Fonction pour afficher un pointeur et la valeur à cette addresse */
void print_pointer(int *p) {
    printf("Pointer address : %p and Pointed value : %d\n" , (void *)p , *p); 
    /* je ne sais pas pourquoi il faut le caster en void (à revoir) */
}

/* Fonction pour changer la valeur à l'adresse d'un pointeur */
void set_pointer(int *p, int n) {
    *p = n;
}

int main(int argc, char const *argv[])
{
    int a = 0;
    int *p = &a;
    print_var(a);
    a = 53;
    print_var(a);
    print_pointer(p);
    set_pointer(p, 42); /* On change la valeur de a sans le passé en argument */
    print_pointer(p);
    print_var(a);

    return EXIT_SUCCESS;
}