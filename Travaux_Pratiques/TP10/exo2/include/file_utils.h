#ifndef __FILES_UTILS_H__
#define __FILES_UTILS_H__

#include <stdio.h>
#include "person.h"

#define BUF_SIZE 256

void parse_file(FILE *file, List *list);

#endif /* __FILES_UTILS_H__ */