#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

// File for sandboxing and trying out code
int main(int argc, char **argv) {
  // Add your code
	/*
  //               20
  //             /    \
  //            /      \
  //           5       30
  //         /   \     /\
  //        /     \   /  \
  //       1      15 25  40
  //            /          \
  //           /            \
  //          9             45
  //        /   \          /
  //       /     \        /
  //      7      12      42
  */
	struct tree_node* root = NULL;

	root = Initialize(root);
	root = Insert(20, root);
	root = Insert(5, root);
	root = Insert(1, root);
	root = Insert(15, root);
	root = Insert(9, root);
	root = Insert(7, root);
	root = Insert(12, root);
	root = Insert(30, root);
	root = Insert(25, root);
	root = Insert(40, root);
	root = Insert(45, root);
	root = Insert(42, root);


	assert(Contains(20, root) == 1);
	assert(Contains(5, root) == 1);
	assert(Contains(1, root) == 1);
	assert(Contains(15, root) == 1);
	assert(Contains(9, root) == 1);
	assert(Contains(7, root) == 1);
	assert(Contains(12, root) == 1);
	assert(Contains(30, root) == 1);
	assert(Contains(25, root) == 1);
	assert(Contains(40, root) == 1);
	assert(Contains(45, root) == 1);
	assert(Contains(42, root) == 1);
	assert(Contains(2, root) == 0);
	assert(Contains(3, root) == 0);

	// (A)
	assert(Empty(Initialize(NULL)));

	// (B) and (C)

	root = Insert(3, root);

	assert(Contains(3, root) == 1);

	root = Remove(3, root);

	assert(Contains(20, root) == 1);
	assert(Contains(5, root) == 1);
	assert(Contains(1, root) == 1);
	assert(Contains(15, root) == 1);
	assert(Contains(9, root) == 1);
	assert(Contains(7, root) == 1);
	assert(Contains(12, root) == 1);
	assert(Contains(30, root) == 1);
	assert(Contains(25, root) == 1);
	assert(Contains(40, root) == 1);
	assert(Contains(45, root) == 1);
	assert(Contains(42, root) == 1);

	assert(Contains(2, root) == 0);
	assert(Contains(3, root) == 0);

	// (D) and (E)
	root = Insert(-1, root);
	root = Insert(-1, root);
	root = Remove(-1, root);
	assert(Contains(-1, root) == 1);
	root = Remove(-1, root);
	assert(Contains(-1, root) == 0);

	root = Remove(45, root);
	root = Remove(42, root);
	root = Insert(16, root);


	assert(Contains(20, root) == 1);
	assert(Contains(5, root) == 1);
	assert(Contains(1, root) == 1);
	assert(Contains(15, root) == 1);
	assert(Contains(9, root) == 1);
	assert(Contains(7, root) == 1);
	assert(Contains(12, root) == 1);
	assert(Contains(30, root) == 1);
	assert(Contains(25, root) == 1);
	assert(Contains(40, root) == 1);
	assert(Contains(45, root) == 0);
	assert(Contains(42, root) == 0);
	assert(Contains(16, root) == 1);

	root = Remove(7, root);



	assert(Contains(16, root) == 1);
	assert(Contains(20, root) == 1);
	assert(Contains(5, root) == 1);
	assert(Contains(1, root) == 1);
	assert(Contains(15, root) == 1);
	assert(Contains(9, root) == 1);
	assert(Contains(7, root) == 0);
	assert(Contains(12, root) == 1);
	assert(Contains(30, root) == 1);
	assert(Contains(25, root) == 1);
	assert(Contains(40, root) == 1);
	assert(Contains(45, root) == 0);

	root = Remove(1, root);
	root = Remove(7, root);
	root = Remove(12, root);
	root = Remove(9, root);
	root = Remove(15, root);
	root = Remove(5, root);
	root = Remove(42, root);
	root = Remove(45, root);
	root = Remove(25, root);
	root = Remove(40, root);
	root = Remove(30, root);
	root = Remove(20, root);
	root = Remove(16, root);

 //print_tree(root,0);

	//free(root);

  return 0;
}