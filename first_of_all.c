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
