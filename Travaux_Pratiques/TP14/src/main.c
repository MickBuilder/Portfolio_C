#include "file_info.h"

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <dir_path>\n", argv[0]);
        return 1;
    }
    
    ftw(argv[1], simple_ls, NB_OF_OPEN_FD);

    print_top_files();
}