#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
    /*FILE *file;*/
    char c;
    /*int count = 0;*/
    int nb_chars = 0;
    int nb_words = 0;
    int nb_lines = 0;
  
    /*if (argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");   */

    if (!isatty(STDIN_FILENO))
    {
        while ((c = getchar()) != EOF)
        {
            if (c == '\n')
            {
                nb_lines++;
            }
            if (c == ' ' || c == '\n' || c == '\t')
            {
                nb_words++;
            }
            nb_chars++;
        }
    }
    
    
    while ((c = fgetc(stdin)) != EOF)
    {   
        nb_chars++;
        if (c == '\n')
        {
            nb_lines++;
        }
        if (c == ' ' || c == '\n' || c == '\t')
        {
            nb_words++;
        }
    }
    printf("%7d %7d %7d\n", nb_lines, nb_words, nb_chars);    

    return EXIT_SUCCESS;
}
