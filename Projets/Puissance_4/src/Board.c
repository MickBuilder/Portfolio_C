#include <stdlib.h>
#include <stdio.h>

#define ROWS        6
#define COLS        7
#define TRUE        1
#define FALSE       0
#define JETON_J1    'X'
#define JETON_J2    'O'

/**
 * @brief      Initialise le tableau de jeu
 * @param      board  The board
 * @return     rien
 */
void init_grid(char board[ROWS][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            board[i][j] = ' ';
        }
    }
}

/**
 * @brief   Affiche le nombre des colonnes
 * @return  rien
 */
void displayColumnNumbers() {
    int i;
    for (i = 0; i < COLS; i++) {
        printf("  %d ", i+1);
    }
    putchar('\n');
}

/**
 * @brief   Affiche le tableau actuel de jeu
 * @param   board  The board
 * @return  rien
 */
void drawBoard(char board[ROWS][COLS]) {
    int i, j;

    displayColumnNumbers();

    for (i = 0; i < ROWS; i++)
    {   
        for (j = 0; j < COLS; j++)
        {
            printf("+---");
        }
        puts("+");

        for (j = 0; j < COLS; j++)
        {
            printf("| %c ", board[i][j]);
        }
        puts("|");
    }

    for (j = 0; j < COLS; j++)
    {
        printf("+---");
    }
    puts("+");

    displayColumnNumbers();
    putchar('\n');
}

/**
 * @brief   Vérifie si la colonne est pleine
 * @param   board  The board
 * @param   col    The col
 * @return  1 si la colonne est pleine, 0 sinon
 */
int isValidMove(char board[ROWS][COLS], int col) {
    if (col <= 0 || col > COLS || board[0][col-1] != ' ') {
        return FALSE;
    }

    return TRUE;
}



/**
 * @brief Récupère le numéro de colonne de chaque joueur
 * @param isPlayer1 
 * @param column 
 */
void getUserAction(int isPlayer1, int *column, char board[ROWS][COLS]) {
    char action;

    do {
        printf("%s : ", isPlayer1 ? "Joueur 1" : "Joueur 2");

        scanf("%c", &action);

        *column = action - '0';
        getchar();
    } while (!isValidMove(board, *column));

    printf("%s : ", isPlayer1 ? "Joueur 1" : "Joueur 2");
    

    /*rewind(stdin); /* Vide le tampon. C'est Important !!! */
    /*fflush(stdin); /* Vide le tampon. C'est Important !!! */

    while ((getchar()) != '\n'); /* Vide le tampon. C'est Important !!! */

    if (action == 'q') {
        exit(0);
    }

    
    printf("%d  \n", *column);
}

/**
 * @brief Place le jeton dans la colonne entre par le joueur
 * 
 * @param board 
 * @param isPlayer1 
 * @param column 
 */
void play(char board[ROWS][COLS], int isPlayer1, int column) {
    int i;
    for (i = ROWS - 1; i >= 0; i--)
    {
        if (board[i][column - 1] == ' ')
        {
            board[i][column - 1] = isPlayer1 ? JETON_J1 : JETON_J2;
            break;
        }
    }
}

int main(int argc, char const *argv[]){

    int isPlayer1 = TRUE;
    int column;
    char board[ROWS][COLS];


    init_grid(board);

    while (TRUE)
    {
        drawBoard(board);
        getUserAction(isPlayer1, &column);
        play(board, isPlayer1, column);
        isPlayer1 = !isPlayer1;
    }
    return EXIT_SUCCESS;
}