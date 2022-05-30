#include "file_info.h"

static FileInfo* top_file_ref;

FileInfo create_file(const char* file_path, int file_size) {
    FileInfo file = {
        .name = "", /*for declaration is it a good way ?*/
        .size = file_size
    };
    strcpy(file.name, file_path);

    return file;
}

void print_file(FileInfo file) {
    printf("%s : %d octets\n", file.name, file.size);
}

void print_top_files() {
    for(int i = 0; i < NB_TOP_LARGER_FILE + 1; i++) {
        print_file(top_file_ref[i]);
    }
}

void init_file(FileInfo array_file[], int array_size) {
    int i;
    for(i = 0; i < array_size; i++) {
        array_file[i] = create_file("No file", -1);
    }
}

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
    /*printf("%-3s :", (type_flag == FTW_D) ? "Dir" : (type_flag == FTW_F) ? "File" : "???");
    printf("%d : %s - %o - %d bytes\n", i, file_path, sb->st_mode, sb->st_size);*/

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