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

Mais je compte continuer à travailler sur ce projet.

###### Problèmes rencontrés

<div style="text-align: justify">
Ce projet a été un défi surtout pour la partie graphisme. Sacahnt qu'il n'y a pas de standard de librairie graphique en C, j'ai utilisé la librairie graphique SDL qui est très bas niveau et n'a pas beaucoup de fonctionnalité. J'ai fait en sorte qu'on puisse jouer au jeu juste avec la commande `make run` en étant sur windows ou linux. 
Au début, j'ai eu beaucoup du mal faire fonctionner le graphisme du jeu, et à faire la liason des éxécutables de la SDL avec mes codes sources. J'ai pris environ une semaine pour résoudre ce problème et j'ai mieux commpris comment fonctionne le processus de liaison de tout programme, j'ai donc pris un peu d'avance sur les TPs du fil rouge accidentellement. 
Ensuite, j'ai eu des problèmes au niveau de la logique du jeu. En effet, à la base, je voulais une balle ronde qui rebondit sur les raquette mais la SDL ne permettant pas de dessiner des cercles, j'ai dans un premier temps utiliser un algorithme de dessin de cercle à base des pixels. Mais avec cet algo, je n'avais pas exactement ce que je voulais comme cercle. J'ai donc crée ma propre fonction me permettant de dessiner le cercle grâce au professeur de TD, Mr Reiters (Merci monsieur :pray:) mais je n'ai pas eu le temps de le terminer. Voici l'avancement actuelle de la fonction : 
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

En conclusion, ce semestre a été très enrichissant pour moi surtout au niveau de l'appronfondissement des notions dejà vues et de l'apprentissage de nouvalle notion telles que la liaison de programme, la fonctionnement d'une bibliothèque graphique. 

## Semestre 2 (Prog C2)

<!-- Ajouter les remarques dans le rapport ... -->

> > > Remarque :  J'aurais aimé écrit le rapport de ce semestre en anglais mais ça n'aurait pas de sens vu que je l'ai déjà commencé en français. Bon assez parlé... Passons aux choses sérieuses. 

Ce semestre a été pour moi plus un approfondissement plus qu'un apprentissage. J'ai aussi profité pour mieux comprendre certaines notions (comme les piles, files, table de hashage, etc) qui étaient encore floues. 

### Productions (du semestre)

#### Travaux Pratiques (du fil rouge!!!)

##### TP9

En parlant, d'approfondissement dans mon introduction, je parlais specifiquement de ce TP. En effet, ce TP traite de l'allocation dynamiqe dans le langage C. J'avais déjà fait de l'allocation dynamique lors de mon DUT mais j'avais compris environ 60% de cette notion. Après avoir pratiqué ce merveilleux TP suivi des cours du professeur, je suis maintenant rassuré de travailler avec les pointeurs en C sans difficultés. Les exercices de ce TP sont graduels, en commençant du plus simple au plus compliqué. Voici un extrait de code permettant de créer un tableau de chaine de caractères. 

```c
char** create_two_dimension_array(int lines, int columns) {
    int i;
    char** array = (char**) malloc(sizeof(char*) * lines);
    if (array == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(0);
    }

    for (i = 0; i < columns; i++) {
        array[i] = create_array(columns);
    }

    return array;
}
```

##### TP10

Ce TP est assez intéressant car il traite non seulement de l'allocation dynamique mais aussi des pointeurs de fonctions. Une notion que je ne maitisais pas totalement non plus. Grâce à ce TP, j'ai pu mieux comprendre ce concept. Mais le TP14 fait un approffondissement plus poussé sur les pointeurs de fonction. Un des exercices est de faire une fonction qui prend deux arguments de n'importe quel type et d'échanger leur valeurs. Voici deux versions de cette fonction. 

- Version dépendant
  
  ```c
  void swap_mem_quick_version(void* z1, void* z2, size_t size)
  {
      void* tmp = malloc(size);
      memcpy(tmp, z1, size);
      memcpy(z1, z2, size);
      memcpy(z2, tmp, size);
      free(tmp);
  }
  ```

- Version non dépendant 
  
  ```c
  void swap_mem(void* z1, void* z2, size_t size) {
      int i;
      char tmp_data;
      char *byte_data_1, *byte_data_2;
  
      if (z1 == NULL || z2 == NULL) {return;}
  
      byte_data_1 = (char*)z1;
      byte_data_2 = (char*)z2;
  
      for (i = 0; i < size; i++)
      {
          tmp_data = byte_data_1[i];
          byte_data_1[i] = byte_data_2[i];
          byte_data_2[i] = tmp_data;
      }
  }
  ```

L'exercice du TP traitant les pointeurs de fonctions consistait à parser des lignes d'un fichier en une structure `Cell` . Ensuite, cette structure est utilisé pour faire une liste chainée de `Cell`.  Le but final de l'exercice est de trier cette liste en fonction de l'age ou du nom de `Cell`.  Comme le sujet le décrire ci-dessous, on voudrait trier de deux manière différentes tout en généralisant le code : 

```
On voudra trier selon deux manières : tout d’abord par l’âge puis alphabétiquement pour
les personnes ayant le même âge. On essayera ensuite de trier alphabétiquement puis par
âge pour les personnes ayant les mêmes nom et prénom
```

Pour cela, la fonction de trie devra prendre, un pointeur de fontion d'ordre en paramètre. La signature de ce pointeur de fonction est : 

```c
int order_func(Cell*, Cell*)
```

- Donc pour trier par age, mon pointeur de fonction ressemble à ça :
  
  ```c
  /**
   * If the age of the first person is equal to the age of the second person, then the function returns
   * the result of the name_order function, otherwise it returns the difference between the age of the
   * first person and the age of the second person
   * 
   * @param person1 The first person to compare
   * @param person2 The second person to compare.
   * 
   * @return the result of the comparison between the two persons.
   */
  int age_order(Person* person1, Person* person2) {
      int age_comparison = person1->age - person2->age;
      return age_comparison == 0 ? name_order(person1, person2) : age_comparison;
  }
  ```

- Pour le trie par nom, il est sous cette forme : 
  
  ```c
  /**
   * If the last names are the same, then compare the ages, otherwise compare the last names
   * 
   * @param person1 A pointer to the first person to compare.
   * @param person2 The second person to compare.
   * 
   * @return the result of the comparison between the two names. If the names are equal, the function
   * returns the result of the comparison between the two ages.
   */
  int name_order(Person* person1, Person* person2) {    
      int diff = strcmp(person1->last_name, person2->last_name);
  
      diff == 0 && (diff = strcmp(person1->first_name, person2->first_name)); /* This is an obscure C. it replace a if statement */
  
      return diff == 0 ? person1->age - person2->age : diff;
  }
  ```

##### TP12

L'objectif de ce TP était du TP était de voir les grandes différences entre listes chaînée et les tables de hashages. Cependant, je n'ai pas réalisé la partie principale de ce TP car on avait déjà fait un exercice similaire en `Algo` qui traitait des tables de hashages.

Dans cet exercice, j'avais représenté ma table de hashage sous cette forme :

```c
typedef struct _link {
    char *word;
    olink *occurrences; /* liste des occurrences */
    struct _link *next;
} link;


typedef struct _table {
    link **bucket;
    int M; /* nombre de seaux */
    int size; /* nombre de mots dans la table */
} table;
```

Le plus important, c'est que le principe des tables de hashage a été compris. 

##### TP14

Comme spoiler dans le TP10, ce TP traite uniquement des pointeurs de fonctions. Il contient un unique exercice qui consiste à utilisé une fonction de la bibliothèque `<ftw.h>` qui prend en paramètre un pointeur de fonction.  La fonction ftw de la bibliothèque <ftw.h> permet de se promener dans l'arborescence des fichiers à partir d'un répertoire racine précisé dans `dirpath` . Le but ici est de récupérer la taille des fichiers pendant le parcours et d'afficher les 10 plus fichiers rencontrés.  La signature du pointeur de fonction est sous cette forme : 

```c
int fn(const char* file_path, const struct stat *sb, int type_flag);
```

Lorsque j'ai commencé le TP, j'avais en tête de faire un code propre sans utilisation de variable globale. Pour cela, j'ai recours au variable static dans mon pointeur de fonction. Tout se passait bien jusqu'au moment j'ai eu besoin d'identifier la fin de ma boucle (sinon, j'aurais une boucle infini). A ce moment là, j'ai été containt d'utiliser une variable static global, ce qui m'a déplu. De ce fait, j'ai compris qu'on ne peut pas éviter les variables globales dans tous les cas. Finalement, j'ai un pointeur de fonction resemblant à ca :

```c
int simple_ls(const char* file_path, const struct stat *sb, int type_flag) {
    static int is_init = 0;
    static FileInfo top_file[NB_TOP_LARGER_FILE + 1];

    FileInfo current_file;
    int j;

    if(!is_init) {
        init_file(top_file, NB_TOP_LARGER_FILE + 1);
        top_file_ref = top_file;
        is_init = 1;
    }

    current_file = create_file(file_path, sb->st_size);

    if(type_flag == FTW_F) {
        j = NB_TOP_LARGER_FILE;
        top_file[NB_TOP_LARGER_FILE] = current_file;

        while (j > 0 && (top_file[j].size > top_file[j-1].size)) {
            FileInfo tmp = top_file[j-1];
            top_file[j-1] = top_file[j];
            top_file[j] = tmp;

            j--;
        }
    }

    return 0;
}  
```



#### Projets

##### We_chat_C

Le but de ce projet est de créer une interface graphique pour un client tcp. Je me suis basé sur le projet d'un camarade de classe. En effet, ce projet était la création d'un serveur tcp en C. Du coup, j'ai décidé de faire la partie client mais aussi lui attribuer une interface graphique. Pour ce fait, j'ai utilisé la bibliothèque `allegro-5` en raison des fonctions utilitaire déjà fait. Le projet a plutôt bien commencé. 



###### Réalisations

- **Client TCP**
  
  J'ai commencé déjà par la partie client tcp, qui a été très rapide vu que j'avais déjà fait de prog système en DUT. La seule difficulté que j'ai rencontré était de rendre le client tcp cross-platform sur ***Window*** et ***Linux***. Puisque l'api système n'est pas le même sur Windows que sur Linux, il fallait utiliser des fonctions différentes en fonction de la platforme. Mais j'ai pu réseoudre ce problème, et j'ai deux fonctions cross-platform qui envoie et reçoive des messages tcp.
  
  ```c
  void send_recv(int i, int sockfd)
  {
  	char send_buf[BUFSIZE];
  	char recv_buf[BUFSIZE];
  	int nbyte_recvd;
  	
  	if (i == 0){
  		fgets(send_buf, BUFSIZE, stdin);
  		if (strcmp(send_buf , "quit\n") == 0) {
  			exit(0);
  		}else
  			send(sockfd, send_buf, strlen(send_buf), 0);
  	}else {
  		nbyte_recvd = recv(sockfd, recv_buf, BUFSIZE, 0);
  		recv_buf[nbyte_recvd] = ' ';
  		printf("%s\n" , recv_buf);
  		fflush(stdout);
  	}
  }
  ```




- **Client Graphique**
  
  C'est la partie qui m'a fait le plus sué sur ce projet. Etant donné que je n'ai pas encore beaucoup d'expéricence en graphique, j'ai perdu les 3/4 de temps sur cette partie. Tout a bien commencé par l'affichage de la fenêtre. Malgré l'avancé de la bibliothèque `allegro-5`, il n'y a pas de fonction pour afficher et récupérer le message d'un champ de texte. C'est la seule partie qui m'a bloqué sur ce projet. Du j'ai commencé à créer ce widget moi-même à base des fonction de base. Et j'ai n'ai pas malheureusement le temps de le finir. Je regrette maintenant de ne pas avoir utilisé la `libMLV` depuis le début pour ce projet. Même si j'aurai un affichage pas trop jolie, le projet serait quand même fonctionnelle.
  
  Pour gérer les évenements sur le champs de texte, j'ai une fonction :
  
  ```c
  void input_on_key_down(ALLEGRO_KEYBOARD_EVENT *keyboard_event, Input *input) {
      int cursor_position = al_ustr_length(input->text);
      if (input->active) {
          switch (keyboard_event->keycode) {
              case ALLEGRO_KEY_LEFT:
                  al_ustr_prev(input->text, &cursor_position);
                  printf("left\n");
                  break;
              case ALLEGRO_KEY_RIGHT:
                  al_ustr_next(input->text, &cursor_position);
                  break;
              case ALLEGRO_KEY_HOME:
                  cursor_position = 0;
                  break;
              case ALLEGRO_KEY_END:
                  cursor_position = al_ustr_length(input->text);
                  break;
              case ALLEGRO_KEY_BACKSPACE:
                  if(al_ustr_prev(input->text, &cursor_position))
                      al_ustr_remove_chr(input->text, cursor_position);
                  break;
              case ALLEGRO_KEY_DELETE:
                  al_ustr_remove_chr(input->text, cursor_position);
                  break;
              case ALLEGRO_KEY_ENTER:
                  input->active = false;
                  break;
              default:
                  if (keyboard_event->unichar >= 32) {
                      al_ustr_insert_chr(input->text, cursor_position, keyboard_event->unichar);
                      //al_ustr_next(input->text, &cursor_position);
                      cursor_position += al_utf8_width(keyboard_event->unichar);
                  }
                  break;
          }
  
          draw_input(input);
      }
  }
  ```

### Conclusion

En somme, ce semestre était plus intéressant que le 1er en raison des approfondissements des notions pas encore claire mais aussi des problèmes rencontré durant le projet de client graphique. Même si je n'ai pu terminé ce projet, je comprends mieux comment fonctionnent les widgets par défaut inclus dans les bibliothèques avancée de graphisme. En plus, je me suis plus concentré sur le coté `code propre` plutôt que la technique ce semestre. J'ai aussi fait un tour rapide sur le platon pour mettre en examen mes connaisance. J'ai fait quelques exercices de la partie `bit à bit` sur platon mais sur la session d'Adrien COSTANDI. 



Pensez à vous hydrater :) .