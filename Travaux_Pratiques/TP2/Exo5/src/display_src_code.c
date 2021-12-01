#include <stdlib.h>
#include <stdio.h>

/*
 * display_src_code - Displays the source code of the program
*/

/*
 * main - Point d'entree
 * @argc: nombre d'arguments
 * @argv: tableau d'arguments
 * Return 0
*/
int main(int argc, char *argv[])
{
    /* Localisation du fichier */
    char* location = "./src/display_src_code.c";
    /* Ouverture du fichier en mode lecture */
    FILE *file = fopen(location, "r");
    char c;

    /* Vérification de l'ouverture du fichier */
    if (file == NULL)
    {
        printf("Impossible d'ouvrir le fichier !\n");
        return EXIT_FAILURE;
    }

    /* Lecture d'un caractere du fichier */
    c = fgetc(file);
    while (c != EOF)
    {
        /* Affichage du caractere lu */
        putchar(c);
        c = fgetc(file);
    }

    fclose(file);

    return EXIT_SUCCESS;
}
