#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  char *el;
  struct node *n_node;
}NODE;

_Bool push(char *v,NODE *n) {
  if(n) {
    push(v,n->n_node);
  } else {
    n->n_node = new_node(v);
    return 0;
  }
}

_Bool pop(NODE *n) {
  if(n->n_node) {
    pop(n->n_node);
  } else {
    free(n);
    return 0;
  }
}
 
NODE *new_node(char *v) {
  NODE *tmp = calloc(1,sizeof(NODE));
        tmp->el = v;
        tmp->n_node = NULL;
        
  return tmp;
}

int main(int argc, char **argv){
   NODE *Stack = new_node("first el");
  
  push("second el" ,Stack);
  push("third el"  ,Stack);
  push("another el",Stack);
  
  pop(Stack);
  
  return 0;
}
