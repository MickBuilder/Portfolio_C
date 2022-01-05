#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define P4_COLONNES (7)
#define P4_LIGNES (6)

#define J1_JETON ('O')
#define J2_JETON ('X')

#define ACT_ERR (0)
#define ACT_JOUER (1)
#define ACT_NOUVELLE_SAISIE (2)
#define ACT_QUITTER (3)

#define STATUT_OK (0)
#define STATUT_GAGNE (1)
#define STATUT_EGALITE (2)

struct position
{
    int colonne;
    int ligne;
};

static void affiche_grille(void);
static void calcule_position(int, struct position *);
static unsigned calcule_nb_jetons_depuis_vers(struct position *, int, int, char);
static unsigned calcule_nb_jetons_depuis(struct position *, char);
static int coup_valide(int);
static int demande_action(int *);
static int demande_nb_joueur(void);
static int grille_complete(void);
static int ia(void);
static void initialise_grille(void);
double nb_aleatoire(void);
int nb_aleatoire_entre(int, int);
static int position_valide(struct position *);
static int statut_jeu(struct position *pos, char);
static unsigned umax(unsigned, unsigned);
static int vider_tampon(FILE *);

static char grille[P4_COLONNES][P4_LIGNES];


static void affiche_grille(void)
{
    /*
     * Affiche la grille pour le ou les joueurs.
     */

    int col;
    int lgn;

    putchar('\n');

    for (col = 1; col <= P4_COLONNES; ++col)
        printf("  %d ", col);

    putchar('\n');
    putchar('+');

    for (col = 1; col <= P4_COLONNES; ++col)
        printf("---+");

    putchar('\n');

    for (lgn = 0; lgn < P4_LIGNES; ++lgn)
    {
        putchar('|');

        for (col = 0; col < P4_COLONNES; ++col)
            if (isalpha(grille[col][lgn]))
                printf(" %c |", grille[col][lgn]);
            else
                printf(" %c |", ' ');

        putchar('\n');
        putchar('+');

        for (col = 1; col <= P4_COLONNES; ++col)
            printf("---+");

        putchar('\n');
    }

    for (col = 1; col <= P4_COLONNES; ++col)
        printf("  %d ", col);

    putchar('\n');
}


static void calcule_position(int coup, struct position *pos)
{
    /*
     * Traduit le coup joué en un numéro de colonne et de ligne.
     */

    int lgn;

    pos->colonne = coup;

    for (lgn = P4_LIGNES - 1; lgn >= 0; --lgn)
        if (grille[pos->colonne][lgn] == ' ')
        {
            pos->ligne = lgn;
            break;
        }
}


static unsigned calcule_nb_jetons_depuis_vers(struct position *pos, int dpl_hrz, int dpl_vrt, char jeton)
{
    /*
     * Calcule le nombre de jetons adajcents identiques depuis une position donnée en se
     * déplaçant de `dpl_hrz` horizontalement et `dpl_vrt` verticalement.
     * La fonction s'arrête si un jeton différent ou une case vide est rencontrée ou si
     * les limites de la grille sont atteintes.
     */

    struct position tmp;
    unsigned nb = 1;

    tmp.colonne = pos->colonne + dpl_hrz;
    tmp.ligne = pos->ligne + dpl_vrt;

    while (position_valide(&tmp))
    {
        if (grille[tmp.colonne][tmp.ligne] == jeton)
            ++nb;
        else
            break;

        tmp.colonne += dpl_hrz;
        tmp.ligne += dpl_vrt;
    }

    return nb;
}


static unsigned calcule_nb_jetons_depuis(struct position *pos, char jeton)
{
    /*
     * Calcule le nombre de jetons adjacents en vérifant la colonne courante,
     * de la ligne courante et des deux obliques courantes.
     * Pour ce faire, la fonction calcule_nb_jeton_depuis_vers() est appelé à
     * plusieurs reprises afin de parcourir la grille suivant la vérification
     * à effectuer.
     */

    unsigned max;

    max = calcule_nb_jetons_depuis_vers(pos, 0, 1, jeton);
    max = umax(max, calcule_nb_jetons_depuis_vers(pos, 1, 0, jeton) + \
    calcule_nb_jetons_depuis_vers(pos, -1, 0, jeton) - 1);
    max = umax(max, calcule_nb_jetons_depuis_vers(pos, 1, 1, jeton) + \
    calcule_nb_jetons_depuis_vers(pos, -1, -1, jeton) - 1);
    max = umax(max, calcule_nb_jetons_depuis_vers(pos, 1, -1, jeton) + \
    calcule_nb_jetons_depuis_vers(pos, -1, 1, jeton) - 1);

    return max;
}


static int coup_valide(int col)
{
    /*
     * Si la colonne renseignée est inférieure ou égale à zéro
     * ou que celle-ci est supérieure à la longueur du tableau
     * ou que la colonne indiquée est saturée
     * alors le coup est invalide.
     */

    if (col <= 0 || col > P4_COLONNES || grille[col - 1][0] != ' ')
        return 0;

    return 1;
}


static int demande_action(int *coup)
{
    /*
     * Demande l'action à effectuer au joueur courant.
     * S'il entre un chiffre, c'est qu'il souhaite jouer.
     * S'il entre la lettre « Q » ou « q », c'est qu'il souhaite quitter.
     * S'il entre autre chose, une nouvelle saisie sera demandée.
     */

    char c;
    int ret = ACT_ERR;

    if (scanf("%d", coup) != 1)
    {
        if (scanf("%c", &c) != 1)
        {
            fprintf(stderr, "Erreur lors de la saisie\n");
            return ret;
        }

        switch (c)
        {
        case 'Q':
        case 'q':
            ret = ACT_QUITTER;
            break;
        default:
            ret = ACT_NOUVELLE_SAISIE;
            break;
        }
    }
    else
        ret = ACT_JOUER;

    if (!vider_tampon(stdin))
    {
         fprintf(stderr, "Erreur lors de la vidange du tampon.\n");
         ret = ACT_ERR;
    }

    return ret;
}


static int demande_nb_joueur(void)
{
    /*
     * Demande et récupère le nombre de joueurs.
     */

    int njoueur = 0;

    while (1)
    {
        printf("Combien de joueurs prennent part à cette partie ? ");

        if (scanf("%d", &njoueur) != 1 && ferror(stdin))
        {
                fprintf(stderr, "Erreur lors de la saisie\n");
                return 0;
        }
        else if (njoueur != 1 && njoueur != 2)
            fprintf(stderr, "Plait-il ?\n");
        else
            break;

        if (!vider_tampon(stdin))
        {
            fprintf(stderr, "Erreur lors de la vidange du tampon.\n");
            return 0;
        }
    }

    return njoueur;
}


static int grille_complete(void)
{
    /*
     * Détermine si la grille de jeu est complète.
     */

    unsigned col;
    unsigned lgn;

    for (col = 0; col < P4_COLONNES; ++col)
        for (lgn = 0; lgn < P4_LIGNES; ++lgn)
            if (grille[col][lgn] == ' ')
                return 0;

    return 1;
}


static int ia(void)
{
    /*
     * Fonction mettant en œuvre l'IA présentée.
     * Assigne une valeur pour chaque colonne libre et retourne ensuite le numéro de
     * colonne ayant la plus haute valeur. Dans le cas où plusieurs valeurs égales sont
     * générées, un numéro de colonne est « choisi au hasard » parmi celles-ci.
     */

    unsigned meilleurs_col[P4_COLONNES];
    unsigned nb_meilleurs_col = 0;
    unsigned max = 0;
    unsigned col;

    for (col = 0; col < P4_COLONNES; ++col)
    {
        struct position pos;
        unsigned longueur;

        if (grille[col][0] != ' ')
            continue;

        calcule_position(col, &pos);
        longueur = calcule_nb_jetons_depuis(&pos, J2_JETON);

        if (longueur >= 4)
            return col;

        longueur = umax(longueur, calcule_nb_jetons_depuis(&pos, J1_JETON));

        if (longueur >= max)
        {
            if (longueur > max)
            {
                nb_meilleurs_col = 0;
                max = longueur;
            }

            meilleurs_col[nb_meilleurs_col++] = col;
        }
    }

    return meilleurs_col[nb_aleatoire_entre(0, nb_meilleurs_col - 1)];
}


static void initialise_grille(void)
{
    /*
     * Initalise les caractères de la grille.
     */

    unsigned col;
    unsigned lgn;

    for (col = 0; col < P4_COLONNES; ++col)
        for (lgn = 0; lgn < P4_LIGNES; ++lgn)
            grille[col][lgn] = ' ';
}


static unsigned umax(unsigned a, unsigned b)
{
    /*
     * Retourne le plus grand des deux arguments.
     */

    return (a > b) ? a : b;
}


double nb_aleatoire(void)
{
    /*
     * Retourne un nombre pseudo-aléatoire compris entre zéro inclus et un exclus.
     */

    return rand() / ((double)RAND_MAX + 1.);
}


int nb_aleatoire_entre(int min, int max)
{
    /*
     * Retourne un nombre pseudo-aléatoire entre `min` et `max` inclus.
     */

    return nb_aleatoire() * (max - min + 1) + min;
}


static int position_valide(struct position *pos)
{
    /*
     * Vérifie que la position fournie est bien comprise dans la grille.
     */

    int ret = 1;

    if (pos->colonne >= P4_COLONNES || pos->colonne < 0)
        ret = 0;
    else if (pos->ligne >= P4_LIGNES || pos->ligne < 0)
        ret = 0;

    return ret;
}


static int statut_jeu(struct position *pos, char jeton)
{
    /*
     * Détermine s'il y a lieu de continuer le jeu ou s'il doit être
     * arrêté parce qu'un joueur a gagné ou que la grille est complète.
     */

    if (grille_complete())
        return STATUT_EGALITE;
    else if (calcule_nb_jetons_depuis(pos, jeton) >= 4)
        return STATUT_GAGNE;

    return STATUT_OK;
}


static int vider_tampon(FILE *fp)
{
    /*
     * Vide les données en attente de lecture du flux spécifié.
     */

    int c;

    do
        c = fgetc(fp);
    while (c != '\n' && c != EOF);

    return ferror(fp) ? 0 : 1;
}


int main(void)
{
    int statut;
    char jeton = J1_JETON;
    int njoueur;

    initialise_grille();
    affiche_grille();
    njoueur = demande_nb_joueur();

    if (!njoueur)
        return EXIT_FAILURE;

    while (1)
    {
        struct position pos;
        int action;
        int coup;

        if (njoueur == 1 && jeton == J2_JETON)
        {
            coup = ia();
            printf("Joueur 2 : %d\n", coup + 1);
            calcule_position(coup, &pos);
        }
        else
        {
            printf("Joueur %d : ", (jeton == J1_JETON) ? 1 : 2);
            action = demande_action(&coup);

            if (action == ACT_ERR)
                return EXIT_FAILURE;
            else if (action == ACT_QUITTER)
                return 0;
            else if (action == ACT_NOUVELLE_SAISIE || !coup_valide(coup))
            {
                fprintf(stderr, "Vous ne pouvez pas jouer à cet endroit\n");
                continue;
            }

            calcule_position(coup - 1, &pos);
        }

        grille[pos.colonne][pos.ligne] = jeton;
        affiche_grille();
        statut = statut_jeu(&pos, jeton);

        if (statut != STATUT_OK)
            break;

        jeton = (jeton == J1_JETON) ? J2_JETON : J1_JETON;    
    }

    if (statut == STATUT_GAGNE)
        printf("Le joueur %d a gagné\n", (jeton == J1_JETON) ? 1 : 2);
    else if (statut == STATUT_EGALITE)
        printf("Égalité\n");

    return 0;
}
