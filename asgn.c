#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "mylib.c"
#include <getopt.h>
#include "container.h"
#include "container.c"

#define KEYMAX 10000
#define STRMAX 1000

int main(int argc, char **argv) {
    FILE *fp = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "r");
    char word[STRMAX];
    char *keys [KEYMAX];
    int itemcount = 0;

    while(fscanf(fp, "%s", word) == 1) {
        //printf("%s\n", word);
        keys[itemcount] = emalloc((strlen(word) + 1) * sizeof keys[0][0]);
        strcpy(keys[itemcount], word);
        itemcount++;
    }
    //alternatively printarray in .h for itemcount and keys
    for (int i = 0; i < itemcount; i++) {
        printf("%s\n", keys[i]);
        free(keys[i]); //should i free it here?
    }

    //easier to assign keys here
    //do we run with ./asgn dictionary.txt -r ?
    //the 2nd stdin is meant to be used for words

    //step 1: create container here
    container my_container = container_new(itemcount, keys);
    for (int i = 0; i < itemcount; i++) {
        container_add(my_container, keys[i]); //it probably works
    }

    const char *optstring = "rspi:h";
    char option;
    while ((option = getopt(argc, argv, optstring)) != EOF) {
        switch (option) {
            case 'r':
                printf("%s", "r chosen");
                
                break;
                /* do something */
                // step 2: set container type as red black tree
                // call container add method in container.c
            case 's':
                printf("s chosen");
                break;
                /* the argument after the -b is available
                   in the global variable ’optarg’ */
            case 'p':
                printf("p chosen");
                /* prinf function */
                break;
                /* do something else */
            case 'i':
                printf("i chosen");
                break;
            case 'h':
                /* help function */
                printf("h chosen");break;
            default:
                printf("null chosen");
                abort();
                break;
                // call container add (flex array?)
                /* if an unknown option is given */
        }
    }

    //words get read from document.txt
    //while(fscanf(fp, "%s", word) == 1)

    //words (and commands?) get read from stdin
    //compare them and print all words that don't match to stdout
    
    fclose(fp);    
    return EXIT_SUCCESS;
}
