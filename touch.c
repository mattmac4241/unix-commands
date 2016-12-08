#include <stdio.h>
#include <strings.h>

//touch create file if it does not exist
void touch(char *file) {
    FILE *fp;
    fp = fopen(file, "w");
    fclose(fp);
}

int main(int argc, char **argv) {
    char file[1024];

    if (argc <= 1) {
        printf("No filename given");
    } else {
        memcpy(file, argv[1], strlen(argv[1])+1);
        touch(file);
    }
    return 0;
}
