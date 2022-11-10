#include <assert.h> /* assert */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */

#include "linked_list.h"

/* functions to create lists */
node *make_node(int v, node *q) {
  node *p = malloc(sizeof(node));
  p->value = v;
  p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list(node *p) {
  node *q;
  while (p != NULL) {
    q = p->next;
    free(p);
    p = q;
  }
}

/* print list to console */
void print_list(node *p) {
  // Add your code for exercise 1
  // There is NO testcode for this
  if(p->next == NULL)
  {
    printf("%d ", p->value);
  }
  else
  {
    printf("%d ", p->value);
    print_list(p->next);
  }
}

int sum_squares(node *p) {
  // Add your code for excercise 2
  // You can find the tests in tests.cpp
if(p == NULL)
{
   return 0;
}
else if(p->next == NULL)
{
   return p->value*p->value;
}
else
{
   return (p->value * p->value) + sum_squares(p->next);
}
}

typedef int (*fn_int_to_int)(int);
int (*sf)(int);


node *map(node *p, fn_int_to_int f) { 
  // Add your code for excercise 3
  if(p == NULL){
    return NULL;
  }

  node *new_list = malloc(sizeof(node));

  int x = f(p->value);
  new_list->value =x;
  new_list->next = map(p->next,f);
  
  return new_list; 
}

int square(int x) { return x * x; }

// example of another function that can be passed to map
// returns the sign of the number
// -1 if negative, 0 if zero, 1 if positive
int sign(int x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }
