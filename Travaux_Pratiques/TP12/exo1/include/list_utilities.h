#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *word;
    struct node *next;
} Node, *List;

void read_file(FILE *file, List *list);

int list_size(List list);

void delete_list(List list);

#endif /* _LIST_H_ */