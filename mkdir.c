#include "stdio.h"
#include <sys/stat.h>
#include <unistd.h>
#include <strings.h>

// create directory
void createDir(char *directory) {
    struct stat st = {0};

    if (stat(directory, &st) == -1) {
        mkdir(directory, 0700);
    }
}

int main(int argc, char **argv) {
    char directory[1024];
    
    if (argc <= 1) {
        printf("No directory name given\n");
    } else {
        memcpy(directory, argv[1], strlen(argv[1])+1);
        createDir(directory);
    }

    return 0;
}
