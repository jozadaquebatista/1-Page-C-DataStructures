# C Data Structures

A bunch of code covering data structures in c programming language.
<img src="http://www.cs.umd.edu/~mount/420/network.gif" align="center" >

Early I'll publish some code on the following subject:
<br /><br />
####@DATASTRUCTURES<br />
- Arrays<br />
- Matrices<br />
- Stack<br />
- Linked Lists<br />
- Queues<br />
- Hash Tables<br />
- Trees<br />
- Graphs<br />

###NOTE: I'm testing one page tutorial and other git features ;D


####@A little Matrix example
```c
  
  #include <time.h>
  
  /* note: int example[10] <- THIS IS AN "ARRAY", NOT A MATRICE */
  
  int int_mat[10][10];
  
  int main(int argc, char **argv) {
  
  srand(time(NULL));
  
  /* filling the matrix */
  for(int i=0; i<=10; i++)
    for(int i=j; j<=10; j++)
      int_mat[i][j] = rand()%(j*i)%7;
      
  return 0;
  }

```

####@Simple NODE
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
####@Basic simplest stack
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

####@Basic LinkedList
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FAILURE -1
#define printi(i)(printf("%d\n",i))

/*   l is the list
 *   n_node represents the next node on the list
 */

typedef struct node {
  int value;
  struct node *n_node;
}NODE;

/*
 *    I'm not covering some issues in add function, like add in any position,
 *    but take it as a challenge and solve it by yourself.
 *    :)
 */

_Bool add(NODE*,int);             //; if sucess returns true.
int del(NODE*,int);               //; returns element deleted.
_Bool list(NODE*);                //; if empty returns false.
int search(NODE*,int);            //; if element in list returns this, otherwise returns -1.
_Bool is_empty(NODE*);            //; verify if current node is vaid for use,
                                  //  if yes, returns 1, else 0 #!UNUSED

_Bool add(NODE *l, int el) {
  if(l->n_node) {
    add(l, el);
  } else {
    l = (NODE*)calloc(1,sizeof(NODE));
    l->value=el;
    l->n_node=NULL;
    return true;
  }
  return false;
}

int del(NODE *l,int el) {
  if(l->value==el) {
    NODE *temp=NULL;
    
    temp=l;
    l=temp->n_node;
    
    free(temp);
    return el;
  } else {
    del(l);
  }
  return FAILURE;
}

_Bool list(NODE *l) {
  if(l) {
    printi(l->value);
    list(i);
  } else {
    return true;
  }
  return false;
}

int search(NODE *l, int el) {
  if(l) {
    if(l->value == el)
      return el;
    else
      search(l,i);
  } else {
    return FAILURE;
  }
}

int main(int argc, char **argv) {
  NODE *lst = calloc(1,sizeof(NODE));
  
  /* ADDING SOME ELEMENTS */
  lst->add(10);
  lst->add(21);
  lst->add(7);
  lst->add(77);
  lst->add(80);
  
  /* SEARCHING, LISTING AND DEL */
  lst->list();
  lst->del(77);
  lst->list();
  printf((lst->search(21)<0?"search not found:. %d\n",\
                            "search found:. %d\n"),\
                            lst->search(21));
}
```

####@A basic Queue
```c
  #include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>
  #include <time.h>
  
  typedef struct node {
    int value;
    struct node *n_node;
  } NODE;
  
  _Bool add(int value, NODE *q);
  int remove(NODE *q);


  _Bool add(int value, NODE *q) {
    if(!q) return false;
  
    NODE *fst_el = q;
         
    while(*q++) {
      if(!q->n_node){
        q->n_node = calloc(1,sizeof(NODE));
        q->n_node->value = value;
        q->n_node->n_node= NULL;
        break;
      }
    }
    q = (NODE*)fst_el;
    return true;
  }
  
  int remove(NODE *q) {
    if(!q) return false;
    
    NODE *fst_el = q;
    int value;
    
    q=(NODE*)q->n_node;
    free(fst_el);
    
    return value;
  }
  
  NODE *new(int value) {
    NODE *new_node = calloc(1, sizeof(NODE));
          new_node->value = value;
          new_node->next  = NULL;
          
    return (NODE*)new_node;
  }
  
  _Bool s_free(NODE *q) { /* My implemenntation of a super recursive free. :D */
    if(q->next) {
      s_free(q->next);
    } else {
      free(q);
      return true;
    }
  }
  
  int main(int argc, char **argv) {
    NODE *queue = new(22);
    
    srand(time(NULL));
    for(int i=0; i<10; i++)
      add(rand()%i*i, queue);
    
    for(int i=0; i<10; i++)
      printf("value %d has been removed.\n", remove(queue));
    
    s_free(queue);
    return 0;
  }
  /* NOTE: 
          I don't tested any code still, I'll do it later, then I will comment the lines for code explanation later. */
```

####@Dynamic static array

```c
  #include <stdio.h>
  #include <stdlib.h>
  #include <stdint.h>
  #include <string.h>
  #include <time.h>
  
  #define ALLOC_SIZE 1
  
  typedef struct friends {
    const char *name;
    const char *celphone;
    const char *address;
    uint8_t age;
  }FRIEND_LIST[100];
  
  int main() {
    FRIEND_LIST flist = calloc(1,sizeof(FRIEND)); /*  Allocates an Instance of 100 pos struc array,
                                                   *  but I could make some more changing the ALLOC_SIZE
                                                   *  to 10 for example.
                                                   */
    strcpy(*(flist)->name,u8"myfriend1",ALLOC_SIZE*10);
    strcpy(*(flist)->celphone,u8"123456",ALLOC_SIZE*10);
    strcpy(*(flist)->address,u8"foo 123",ALLOC_SIZE*10);
    *(flist)->age = 26;
    
    strcpy(*(flist+1)->name,u8"myfriend2",ALLOC_SIZE*10);
    strcpy(*(flist+1)->celphone,u8"123456",ALLOC_SIZE*10);
    strcpy(*(flist+1)->address,u8"foo 123",ALLOC_SIZE*10);
    *(flist+1)->age = 26;
    
    /* Then I could free the entire structure. */
    free(flist); // bye ...
    
    return 0;
  }
```

####@Recursion
```c
  #include <stdio.h>
  #include <stdlib.h>
  #include <stdint.h>
  
  int fib(int i) {
    if(i<=0) return 0;
    return i+fib(i-1);
  }
  
  int main(int argc, char **argv) {
    printf("fibonacci of 7 is %d.\n",fib(7));
    return 0;
  }
```
