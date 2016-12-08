#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

//catWithFile opens and displays the contents of a file line by line 
void catWithFile(char *file) {
    FILE *fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(file, "r");
    if (fp == NULL) {
        printf("Failed to open file %s\n", file);
        return; //break to prevent segmentation fault
    }
    while ((read = getline(&line, &len, fp)) != -1) {
        printf("%s", line);
    }
    
    fclose(fp);
}

//cat reads line by line from standard input
void cat() {
    char str[256];
    for(;;){
        fgets(str, 256, stdin); // use fgets becuase gets is unsafe
        printf("%s", str);
    }
}

int main(int argc, char **argv) {
    char file[1024];
    int i;

    if(argc < 2) {
        cat(); 
    } else {
        i = 1;
        while(argv[i] != NULL) {
            memcpy(file, argv[i], strlen(argv[1])+1);
            catWithFile(file);
            i++;
        }
    }
    return 0;
}   

