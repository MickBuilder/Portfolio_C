#include <stdlib.h>
#include <stdio.h>

/**
 * is_minuscule - verifie si une chaine de caractere est en minuscule
 * @word: chaine de caractere a verifier
 * Return: 1 si la chaine est en minuscule, 0 sinon
*/
int is_minuscule(char word[])
{
    int i = 0;
    while (word[i] != '\0')
    {
        if (word[i] < 'a' || word[i] > 'z')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/**
 * is_numeric - verifie si une chaine de caractere est numerique
 * @word: chaine de caractere a verifier
 * Return: 1 si la chaine est numerique, 0 sinon
*/
int is_numeric(char word[])
{
    int i = 0;
    while (word[i] != '\0')
    {
        if (word[i] < '0' || word[i] > '9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/* Convertir en base 26 */


/**
 * Convertir minuscule en majuscule
 * A revoir plus tard */
/*void min_to_maj(char word[])
{
    int i = 0;
    while (word[i] != '\0')
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] = word[i] - 32;
        }
        i++;
    }
}*/

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <mot_minuscule>/<nombre>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (!atoi(argv[1]))
    {
        /* Vérifier si une chaine est minuscule */
        int i = 0;
        int nombre = 0;
        while (argv[1][i])
        {
            if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
            {
                printf("L'argumument donne doit etre un nombre ou un mot en minuscule\n");
                return EXIT_FAILURE;
            }
            i++;
        }

        /* Convertir la chaine en nombre */
        printf("%d\n", 'j' - 'a');
        
        i = 0;
        while (argv[1][i])
        {
            nombre = nombre * 10 + (argv[1][i] - 'a');
            i++;
        }
        printf("%d\n", nombre);
    }
    else
    {
        printf("%d\n", atoi(argv[1]));
    }  

    return EXIT_SUCCESS;
}
