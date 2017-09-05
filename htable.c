#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"

struct htablerec {
    int capacity;
    int *num_keys;
    int *frequencies;
    char **keys;
};

htable htable_new(int capacity) {
    int i;
    /* declare a htable and allocate memory as appropriate */
    htable hash = emalloc(sizeof *hash);
    /* initialise the htable's capacity and number of keys appropriately */
    hash->capacity = capacity;
    hash->num_keys = 0;
    /* allocate htable's frequency array to be able to store enough integers */
    hash->frequencies = emalloc(hash->capacity * sizeof hash->frequencies[0]);
    /* allocate htable's keys array to be able to store enough strings */
    hash->keys = emalloc(hash->capacity * sizeof (char*));
    /* set each frequency and key to their initial values */
    for(i=0; i<capacity; i++){
        hash->frequencies[i] = 0;
        hash->keys[i] = NULL;
    }
    /* return the hash table */
    return hash;
}

static unsigned int htable_word_to_int(char *word) {
    unsigned int result = 0;
    
    while (*word != '\0') {
        result = (*word++ + 31 * result);
    }
    return result;
}

int htable_insert(htable h, char *item){
  int i;
  /* convert item to int */
  unsigned int item_int = htable_word_to_int(item);
  /* position = int % capacity */
 unsigned  int position = item_int % h->capacity;
  /* check string at that position */
  if(h->keys[position]==NULL){
    /* 1 */
    /* printf("case 1\n");
       printf("putting %s into position %d\n", item, position);*/
    h->keys[position] = emalloc(strlen(item)+1 * sizeof h->keys[position]);
    strcpy(h->keys[position], item);    
    h->frequencies[position]++;
    h->num_keys++;
    return 1;
  }else if(strcmp(h->keys[position],item)==0){
    /* 2 */
    /* printf("case 2\n");
       printf("%s is already in position %d, incrementing frequency\n", item, position);*/
    h->frequencies[position]++;
    return h->frequencies[position];
  }else{
    for(i=1; i<h->capacity; i++){
      if(h->keys[position]==NULL){
	  h->keys[position] = emalloc(strlen(item)+1 * sizeof h->keys[position]);
	  strcpy(h->keys[position], item);   
	  h->frequencies[position] = 1;
	  h->num_keys++;
	  return 1;
      }else if(strcmp(h->keys[position],item) == 0){
	h->frequencies[i]++;
	return h->frequencies[position];
      }
    }
  }
  return 0;
}

void htable_print(htable h, FILE *dest){
  int i;
  printf("htable_print:\n");
  for(i=0; i<h->capacity; i++){
    if(h->frequencies[i] > 0){
      fprintf(dest, "There are %d %s's\n", h->frequencies[i], h->keys[i]);
    }
  }
}

void htable_free(htable h){
    int i;
    for(i=0; i<h->capacity; i++){
      free(h->keys[i]);
    }
    free(h->keys);
    free(h->frequencies);
    free(h);
}
