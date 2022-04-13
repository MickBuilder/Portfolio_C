#include "person.h"
#include "file_utils.h"

int main(int argc, char const *argv[])
{
    const char* filename = "liste_nom.txt";
    parse_file(filename);
    return 0;
}
