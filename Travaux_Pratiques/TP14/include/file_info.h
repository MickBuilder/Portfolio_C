#ifndef __FILE_INFO_H_
#define __FILE_INFO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ftw.h>

#define NB_OF_OPEN_FD 10
#define MAX_SIZE 4096
#define NB_TOP_LARGER_FILE 10

typedef struct {
    char name[MAX_SIZE];
    int size;
} FileInfo;

FileInfo create_file(const char* file_path, int file_size);

void print_file(FileInfo file);

void init_file(FileInfo array_file[], int array_size);

void print_top_files();

int simple_ls(const char* file_path, const struct stat *sb, int type_flag);

#endif /* __FILE_INFO_H_ */