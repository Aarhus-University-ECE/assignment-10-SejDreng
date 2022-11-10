#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node *Insert(int x, struct tree_node *t) {
  // Insert item x into the tree t
  if(t == NULL)
  {
    printf("%d inserted \n",x);
    t = malloc(sizeof(tree_node));
    t->item = x;
    t->left = NULL;
    t->right = NULL;
    return t; 
  }
  if(x > t->item)
  {  
    t->right = Insert(x,t->right);
  }
  else if(x < t->item)
  {  
    t->left = Insert(x,t->left);
  }
  else if(x == t->item) 
  {
    t->left = Insert(x,t->left);
  }
    return t;
}

struct tree_node *Remove(int x, struct tree_node *t) {
  // Remove one item from the tree t
  if(t == NULL)
  {
    return NULL;
  }
  if(x == t->item)
  {
    if(t->left == NULL && t->right == NULL)
    {
      t = NULL;
      free(t);
    }
    else if(t->left != NULL && t->right == NULL)
    {
      t = t->left;
      free(t->left);
    }
    else if(t->left == NULL && t->right != NULL)
    {
      t = t->right;
      free(t->right);
    }
    else
    {
      if(t->left->right != NULL)
      {
        tree_node *temp = t->left->right;
        while (temp->right != NULL)
        {
          temp = temp->right;
        }
        temp->left = t->left;
        temp->right = t->right;
        t = temp;
        free(temp);
      }
      else
      {
        t->left->right->right = t->right;
        t->left->right->left = t->left;
        t = t->left->right;
        free(t->left->right);
      }
    }
    return t;
  }


  if(x > t->item)
  {
    t->right = Remove(x,t->right);
  }

  else if(x < t->item)
  {
    t->left = Remove(x,t->left);
  }

  return t;
}

int Contains(int x, struct tree_node *t) {

  // Return true if the tree t contains item x. Return false otherwise.
  if(t == NULL)
  {
    return 0;
  }
  if(x == t->item)
  {
    return 1;
  }
  else if(x > t->item)
  {
   return Contains(x,t->right);
  }
  else if(x < t->item)
  {
    return Contains(x,t->left);
  }
}

struct tree_node *Initialize(struct tree_node *t) {
  // Create an empty tree
  t == NULL;
  return t;
}

int Empty(struct tree_node *t) {
  if(t == NULL)
  {
    return 1;
  }
  return 0;
}

int Full(struct tree_node *t) {
  // Test if full
  // Tree is never full
  return 0;
}


/*void print_tree (tree_node * p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->item);


  if (p->left)
    {
      print_tree (p->left, depth + 1);
    }

  if (p->right)
    print_tree (p->right, depth + 1);
}*/