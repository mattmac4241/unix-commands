#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <dirent.h>
#include <strings.h>

//Open directory and list files
void ls(char *directory) {
    DIR *pDir;
    struct dirent *pDirent;

    pDir = opendir(directory);
    if (pDir == NULL)
        printf("failed to open directory");
    
    while ((pDirent = readdir(pDir)) != NULL) {
        printf("%s\t", pDirent->d_name);
    }
    printf("\n");
    closedir(pDir);
}


int main(int argc, char **argv) {
    char cwd[1024];

    if (argc > 1) {
        memcpy(cwd, argv[1], strlen(argv[1])+1);
        ls(cwd);
    
    } else {
        if (getcwd(cwd, sizeof(cwd)) != NULL)
            ls(cwd);
        else
            perror("getcwd() error");
    }
    
    return 0;
}
