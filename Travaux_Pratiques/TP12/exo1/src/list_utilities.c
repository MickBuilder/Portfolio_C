#include "list_utilities.h"

void create_node(Node **node, char *word) {
    *node = (Node *) malloc(sizeof(Node));
    (*node)->word = (char *) malloc(sizeof(char) * (strlen(word) + 1));
    strcpy((*node)->word, word);
    (*node)->next = NULL;
}

Node* find_node(List list, char *word) {
    Node *tmp = list;
    while (tmp != NULL && strcmp(tmp->word, word) != 0) {
        tmp = tmp->next;
    }
    return tmp;
}

void insert_node_front(List *list, char *word) {
    Node *new_node = NULL; 
    create_node(&new_node, word);
    new_node->next = *list;
    *list = new_node;
}

int list_size(List list) {
    int size = 0;
    while (list != NULL) {
        size++;
        list = list->next;
    }
    return size;
}

void delete_node(Node *node) {
    free(node->word);
    free(node);
}

void delete_list(List list) {
    Node *cur = list;
    while (cur != NULL) {
        Node *tmp = cur->next;
        delete_node(tmp);
        cur = tmp;
    }
}

void read_file(FILE *file, List *list) {
    char word[100];
    while (fscanf(file, "%s", word) != -1) {
        Node *node = find_node(*list, word);
        if (node == NULL) {
            insert_node_front(list, word);
        }
    }
}