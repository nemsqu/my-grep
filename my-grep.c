#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    // not enough arguments
    if(argc == 1){
        printf("my-grep: searchterm [file ...]\n");
        exit(1);
    }
    FILE *pfile;
    char *buffer = NULL;
    size_t len = 0;
    char *searchTerm = argv[1];

    // input from file(s)
    if(argc > 2){
        // loop through all files
        for(int i=2; i < argc; i++){
            if((pfile = fopen(argv[i], "r")) == NULL){
                printf("my-grep: cannot open file\n");
                exit(1);
            }
            while(getline(&buffer, &len, pfile) != -1){
                // check if searchterm is in the line https://www.delftstack.com/howto/c/string-contains-in-c/
                if ((strstr(buffer, searchTerm)) != NULL){
                    printf("%s", buffer);
                }
            }
            fclose(pfile);
        }
    } else {
        //input from user input
        while(getline(&buffer, &len, stdin) != -1){
            // check if searchterm is in the line https://www.delftstack.com/howto/c/string-contains-in-c/
            if ((strstr(buffer, searchTerm)) != NULL){
                printf("%s", buffer);
            }
        }
    }

    return 0;
}