# Portfolio_C

<div style="text-align: justify">
  Salut !  <img title="" src="https://raw.githubusercontent.com/MartinHeinz/MartinHeinz/master/wave.gif" alt="Hello" width="50" data-align="inline"> <br>
  Bienvenu sur mon portfolio. Au cours de la lecture de ce portfolio, vous decouverez qui suis-je, les compétences acquises sur le langage C, les réalisations que j'ai pu faire ce semestre et les celles qui restent à acquérir.
</div>

## Présentation

<div style="text-align: justify">
  Tout d'abord, je suis étudiant en 1er année de cursus ingénieur à l'ESIPE Marne-la-Vallée. 
  Je viens d'un DUT Informatique. J'ai commencé à programmer en C la 1er fois en 1ère année de DUT Informatique et j'ai coder en l'année suivante aussi. Mais malgré, ces deux années de programmation en C, il me restait toujours des compétences à revoir en C telles que : les listes chainées, les opérations bits à bits, les piles, les files et surtout le coté algorithmie de la programmation.
</div>

## Introduction

## Semestre 1 (Prog C1)

### Objectifs de progression

<div style="text-align: justify">
  Mon objectifs est de mieux comprendre les notions sur lesquelles je bloque en suivant les TPs du fil rouge mais aussi en faisant des projets utilisant toutes les notions des TPs du fil rouge. Ci-dessous se trouve les objectifs que j'aimerais atteindre pour chaque notion de ce langage.
</div>

| Notions          | Points total |
| ---------------- | ------------ |
| Entrée/Sortie    | 5            |
| Types de données | 5            |
| Programme        | 5            |
| Modules          | 3            |
| Compilation      | 5            |
| Récursivité      | 2            |
| Tableaux         | 4            |
| Pointeurs        | 2            |
| Structures       | 2            |
| Bibliothèque     | 1            |

### Productions

#### Travaux Pratiques

##### TP2 :

Le TP2 a servi de rappel sur comment coder basiquement en C. J’ai pu revoir certaines bases pour confirmer les notions de bases que j'avais déjà acquises.

L’exercice 5 m'a permis de revoir le fonctionnement des fichiers en C.

> NB : Vous trouverez toutes les notions abordés dans le TP2 sur le [récapitulatif des notions](#récaputilatif-des-notions)

##### TP 3 :

<div style="text-align: justify">
  Le TP3 m’a permis également à revoir certaines bases, ceci dit, je n’ai pas terminés tous les exercices. En effet, à cause d'un défi que je me suis lancé, je n'ai pas eu le temps de revenir sur les exercices 2 et 3.

  Etant donnée, la facilité de l'exercice 1, je me suis permis de m'intéresser aux tests unitaire (TDD)
  pour avoir quelque chose d'amusant. Ca été un sacré défi. Au début, c'était très difficile à saisir le concept mais au fur et à mesure de faire d'approfondir, j'ai mieux saisir le concept des tests.
  Pour ce faire, j'ai utilisé un petite bibliothèque minimaliste, en effet il suffit juste d'inclure un fichier d'entêtes `.h` dans mon code source de test afin de pouvoir tester les fonctions de l'exercice.

  Finalement, je n’ai pas pris le temps de revenir sur les exercices que je n'ai pas terminés, mais j'ai commencé à réfléchir à un projet à faire.

</div>

> NB : Vous trouverez toutes les notions abordés dans le TP2 sur le [récapitulatif des notions](#récaputilatif-des-notions)

##### TP 4 :

Ce TP consistait à remplir les fonctions pour implémenter une pile en C

Je n’ai rien fait d’exceptionnel pour faire la pile, j’ai suivis le TP et remplit les fonctions comme il me semble qu’elle devait être codée.

J’ai cependant mieux compris comment fonctionnait une pile.

> NB : Vous trouverez toutes les notions abordés dans le TP2 sur le [récapitulatif des notions](#récaputilatif-des-notions)

##### TP 5 :

Ce TP a le grand avantage de tout revoir et de tout utiliser sur les tableaux, et fait un très bon exercice pour mieux appréhender les tableaux.

> NB : Vous trouverez toutes les notions abordés dans le TP2 sur le [récapitulatif des notions](#récaputilatif-des-notions)

##### TP 6 :

Je n'ai pas eu le temps de terminer proprement le TP6, j'ai juste commencer l'exercice 1 qui est un préliminaire. Mais grâce à ça, j'ai pu constater que ce TP porte sur la récursivité.

> NB : Vous trouverez toutes les notions abordés dans le TP2 sur le [récapitulatif des notions](#récaputilatif-des-notions)

#### Projets

##### Pong Game

Le Pong est jeu vidéo dans lequel il faut controler des raquêttes afin de faire rebondir une balle et de marquer des points. J'ai choisir comme projet de créer ce jeu vidéo en langage C. 

###### Objectifs

<div style="text-align: justify">
  L'objectif de ce jeu est d'avoir un jeu de pong fonctionnel utilisant le son pour le rebond des balles, un menu pour choisir la diffculté (vitesse de la balle) du jeu, de jouer contre une IA, un effet de trainée pour la balle et un score pour chaque joueur(Odinateur ou humain).
</div>

###### Production

Finalement, j'ai créer un jeu qui fonctionne mais sans les fonctionnalités prévues à la base telles que:

- le systeme de score
- l'IA
- le son lorsque la balle rebondit
- l'effet de trainée de la balle

###### Problèmes rencontrés

<div style="text-align: justify">
Ce projet a été un défi surtout pour la partie graphisme. Sacahnt qu'il n'y a pas de standard de librairie graphique en C, j'ai utilisé la librairie graphique SDL qui est très bas niveau et n'a pas beaucoup de fonctionnalité. J'ai fait en sorte qu'on puisse jouer au jeu juste avec la commande `make run` en étant sur windows ou linux. 
Au début, j'ai eu beaucoup du mal faire fonctionner le graphisme du jeu, et à faire la liason des éxécutables de la SDL avec mes codes sources. J'ai pris environ une semaine pour résoudre ce problème et j'ai mieux commpris comment fonctionne le processus de liaison de tout programme, j'ai donc pris un peu d'avance sur les TPs du fil rouge accidentellement. 
Ensuite, j'ai eu des problèmes au niveau de la logique du jeu. En effet, à la base, je voulais une balle ronde qui rebondit sur les raquette mais la SDL ne permettant pas de dessiner des cercles, j'ai dans un premier temps utiliser un algorithme de dessin de cercle à base des pixels. Mais avec cet algo, je n'avais pas exactement ce que je voulais comme cercle. J'ai donc crée ma propre fonction me permettant de dessiner le cercle grâce au professeur de TD, Mr Reiters (Merci monsieur :pray:) mais je n'ai pas eu le temps de le terminer. voici l'avancement actuelle de la fonction : 
</div>

```c
/* Remarque du prof : Le prf m'a aider à créer cette fonction */
int SDL_RenderFillCircle(SDL_Renderer * renderer, int x, int y, int radius) 
{
    int d, status, h;
    status = 0;
    h = radius * 2;
    for (d = 0; d < radius; d++)
    {
        status += SDL_RenderDrawLine(renderer, x + d, y - h/2, x + d, y + h/2);
        status += SDL_RenderDrawLine(renderer, x - d - 1, y - h/2, x - d - 1, y + h/2);
        h--;
    }
    return status;
}
```

> NB : Vous trouverez toutes les notions abordés dans le TP2 sur le [récapitulatif des notions](#récaputilatif-des-notions)

### Récaputilatif des notions

| Notions                | TP2 | TP3 | TP4 | TP5 | TP6 | Pong |
| ---------------------- | --- | --- | --- | --- | --- | ---- |
| I/O                    | 1   | 1   | 1   | 1   | 1   |      |
| Type                   | 1   | 1   | 1   | 1   | 1   | 2    |
| Programme              | 1   | 1   | 1   | 1   | 1   | 3    |
| Module                 |     |     | 1   |     | 1   | 2    |
| Compilation            | 1   | 1   | 1   | 1   | 1   | 2    |
| Récursion              | 1   | 1   |     | 1   | 2   |      |
| Tableaux               |     | 1   |     | 1   | 1   |      |
| Pointeurs              |     |     |     | 1   | 1   | 1    |
| Structures             |     |     |     |     |     | 2    |
| Allocation             |     |     |     |     |     |      |
| Fichier                | 1   |     |     |     | 1   |      |
| Bit à bit              |     |     |     |     |     |      |
| Pointeurs de fonctions |     |     |     |     |     |      |
| Bibliothèque           |     |     | 1   |     |     | 3    |
| **Pts Total**          | 6   | 6   | 6   | 7   | 10  | 15   |

### Conclusion

En conclusion, 