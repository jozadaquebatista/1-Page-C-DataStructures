#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
  char *el;
  struct node *n_node;
}NODE;

_Bool push(const char*,NODE*);
_Bool pop(NODE*);
NODE *new_node(const char*);

_Bool push(const char *v,NODE *n) {
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
 
NODE *new_node(const char *v) {
  NODE *tmp = calloc(1,sizeof(NODE));
        strncpy(tmp->el,v,strlen(v));
        tmp->n_node = NULL;
        
  return (NODE*)tmp;
}  

int main(int argc, char **argv){
   NODE *Stack = new_node("first el");
  
  push("second el" ,Stack);
  push("third el"  ,Stack);
  push("another el",Stack);
  
  pop(Stack);
  
  return 0;
}m
