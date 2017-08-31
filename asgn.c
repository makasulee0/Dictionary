/*
The data structure that you will use to hold the words is a hash table. Each position in the
hash table will be a container which can hold multiple items (i.e. chaining). You will create
two types of container, one using a very simple chaining method, and one using a more robust
chaining method.

You should use the hash function given in lab 12 for this assignment. We can simulate a bad
hash function simply by reducing the size of the hash table. This will ensure that lots of items
hash to the same position in the table.

Your program will create a hash table and fill it with words read from a file specified on the
command line. Your hash table will be made up of containers which can hold any amount of items. A
container is really just a wrapper for a flexarray or a red-black tree.

Once all of the words in the file have been put into the hash table, words get read from stdin. If
a word read from stdin is not found in the hash table then it gets printed to stdout, otherwise
nothing happens.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEYMAX 10000
#define STRMAX 1000

void *emalloc(size_t s) {
    void *result = malloc(s);
    if (NULL == result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

int main(int argc, char **argv) {
    FILE *fp = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "r");
    char word[STRMAX];
    char *keys [KEYMAX];
    int itemcount = 0;

    //pass keys to the container method -- how?
    while(fscanf(fp, "%s", word) == 1) {
        //printf("%s\n", word);
        keys[itemcount] = emalloc((strlen(word) + 1) * sizeof keys[0][0]);
        strcpy(keys[itemcount], word);
        itemcount++;
    }
    for (int i = 0; i < itemcount; i++) {
        printf("%s\n", keys[i]);
        free(keys[i]); //should i free it here?
    }

    //words get read from document.txt
    while(fscanf(fp, "%s", word) == 1)

    //after that, words get read from stdin

    //compare them and print all words that don't match to stdout
    
    fclose(fp);    
    return EXIT_SUCCESS;
}
