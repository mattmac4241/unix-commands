#include <stdio.h>
#include <strings.h>

void rm(char *file) {
    int ret;

    ret = remove(file);
    if (ret != 0) {
        printf("Failed to delete file");
    }
}



int main(int argc, char **argv) {
    char file[1024];

    if (argc <= 1) {
        printf("No filename given");
    } else {
        memcpy(file, argv[1], strlen(argv[1])+1);
        rm(file);
    }

    return 0;
}
