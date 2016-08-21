#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
  char *el;
  struct node *n_node;
};

_Bool push(char *v,struct node *n) {
  if(n) {
    push(n->next);
  } else {
    n->next = new(v);
    return 0;
  }
}

_Bool pop(struct node *n) {
  if(n->next) {
    pop(n->next);
  } else {
    free(n);
    return 0;
  }
}

struct node *new(char *v) {
  node *tmp = calloc(1,sizeof(node))
        tmp->el = v;
        tmp->n_node = NULL;
        
  return tmp;
}

int main(int argc, char **argv){
  node *Stack = new("first el");
  
  Stack->push("second el");
  Stack->push("third el);
  Stack->push("another el");
  
  Stack->pop();
  
  return 0;
}
