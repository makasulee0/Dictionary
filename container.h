#ifndef CONTAINER_E_
#define CONTAINER_E_

typedef enum container_e {FLEX_ARRAY, RED_BLACK_TREE} *container_t;
typedef struct containerrec *container;

extern void container_add(container c, char *word);
//extern void container_free(container c);
extern container container_new(int itemcount, char **a);
//probably need another constructor for container_t

#endif
