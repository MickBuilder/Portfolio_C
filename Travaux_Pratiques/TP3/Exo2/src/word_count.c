#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * void word_count - counts the number of words in a string
 * @nb_words: number of words
 * @nb_chars: number of characters
 * @nb_lines: number of lines
 * @filename: name of the file
 * Return: nothing
 * 
 * Description: counts the number of words, characters and lines in a file
*/
void word_count_file(int* nb_words, int* nb_chars, int* nb_lines, char* filename) {
    FILE* f = fopen(filename, "r");
    char c;
    int word = 0;
    int line = 0;
    int char_count = 0;
    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') {
            line++;
        }
        if (c == ' ' || c == '\n') {
            word++;
        }
        char_count++;
    }
    fclose(f);
    *nb_words = word;
    *nb_chars = char_count;
    *nb_lines = line;
}

/**
 * word_count_no_file - counts the number of words in a string
 * @nb_words: number of words
 * @nb_chars: number of characters
 * @nb_lines: number of lines
 * Return: nothing
 * 
 * Description:
 * This function counts the number of words, characters and lines in a string
 * without a file.
*/
void word_count_no_file(int* nb_words, int* nb_chars, int* nb_lines) {
    char c;
    int word = 0;
    int line = 0;
    int char_count = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            line++;
        }
        if (c == ' ' || c == '\n') {
            word++;
        }
        char_count++;
    }
    *nb_words = word;
    *nb_chars = char_count;
    *nb_lines = line;
}

/**
 * main - counts the number of words, characters and lines in a file
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 if success
 * 
 * Description:
 * This function counts the number of words, characters and lines in a file
 * or in a string.
*/
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
