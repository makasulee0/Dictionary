#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
//typedef enum prevents other values to besides {} added to the enum

//eg typedef enum Ranks {? !} Order
//Order data = 20 will send error message, only Order ? will work

//That means - container_e will only accept FLEX_ARRAY or RED_BLACK_TREE from
//container_t. But how does this relate with containerrec?

//Tested - we need the struct for containerrec - containerrec should act like container_e

//https://stackoverflow.com/questions/20426716/how-do-i-use-typedef-and-typedef-enum-in-c

struct containerrec {
    container_t type;
    void *contents;
};

container container_new(int itemcount, char **a) {
    container result = emalloc(sizeof *result);
    result->type = RED_BLACK_TREE;
    result->contents = emalloc(itemcount * sizeof a[0]);
    return result;
}

void container_add(container c, char *word) {
    if (c->type == RED_BLACK_TREE) {
        printf("rbt\n");
        //c->contents = rbt_insert(c->contents, word);
    } else {
        printf("flex");
        //flexarray_append(c->contents, word);
    }
}

//void container_free() {}
