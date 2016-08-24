# Data Structures with C/C++

A bunch of code covering data structures in cplusplus
<img src="http://www.cs.umd.edu/~mount/420/network.gif" align="center" >

Early I'll publish some code on the following subject:
<br /><br />
####@DATASTRUCTURES<br />
- Arrays<br />
- Matrices<br />
- Stack<br />
- Linked Lists<br />
- Queues<br />
- Deques<br />
- Hash Tables<br />
- Trees<br />
- Graphs<br />

###NOTE: I'm testing one page tutorial and other git features ;D
##Simple NODE
```c
/*
* What do you think is a Node in DS ?
* the bellow example, gives you an sample Node DS.
*/

/* DS SAMPLE */

struct node {
  char *str;
  int  qt;
  union {
    _Bool   valid;
    uint8_t i;
    char    c;
  }
}

/* That is a very pure simple basic datastructer in C, just simple. That's it. */
```
#basic simplest stack
```c
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
}
```
