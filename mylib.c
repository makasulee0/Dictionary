#include <stdio.h> /* for fprintf */
#include <stdlib.h> /* for size_t, malloc, realloc, exit */
#include "mylib.h"

void *emalloc(size_t s) {
    /* implementation of emalloc goes here */
    void *result = malloc(s);
    if(NULL == result){
        exit(EXIT_FAILURE);
    }
    return result;
}
void *erealloc(void *p, size_t s) {
    /* implementation of erealloc goes here */
    void *result = realloc(p , s);
    if (NULL == result) {
        fprintf(stderr, "memory reallocation failed.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

static void array_print(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%s\n", a[i]);
    }
}
