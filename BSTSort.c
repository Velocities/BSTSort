#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BSTSort.h"

static Node* root;

static unsigned int index = 0;

static int* arrStorage;

// This function creates a new node with the given value, initializes its occurrence count to 1, and sets its left and right child pointers to NULL.
// (Our "Node constructor")
Node* makeNode(int value) {
  Node *result = (Node *) malloc(sizeof(Node));
  result->val = value;
  result->occurrences = 1;
  result->left = NULL;
  result->right = NULL;
  return result;
}

/*
This function takes an array of integers arr and its size size as input. It creates a new binary search tree with the 
first element of the array as the root node, and inserts each subsequent element into the tree using the insert() function. 
After the tree has been constructed, it populates arrStorage with the sorted values by traversing the tree in order and 
storing each value the appropriate number of times. Finally, it resets the static index variable to 0.
*/
void BSTSort(int arr[], int size) {
  root = makeNode(arr[0]);
  // Construct the BST
  for (int i = 1; i < size; i += 1) {
    insert(root, arr[i]);
  }
  // Input BST into array
  int index = 0;
  arrStorage = arr;
  inOrderInsert(root);
  arrStorage = NULL;
  root = NULL;
  index = 0;
}

/*
This function takes a node pointer n and a value insertionVal as input. It inserts the value into 
the binary search tree rooted at n, incrementing the occurrence count for the existing node if the 
value is already in the tree, or creating a new node and inserting it appropriately if the value is 
not already in the tree.
*/
static void insert(Node *n, int insertionVal) {
  while (n != NULL) {
    if (insertionVal == n->val) {
      n->occurrences += 1;
      n = NULL;
    } else if (insertionVal > n->val) {
      if (n->right != NULL) {
        n = n->right;
      } else {
        n->right = makeNode(insertionVal);
        n = NULL;
      }
    } else {
      if (n->left != NULL) {
        n = n->left;
      } else {
        n->left = makeNode(insertionVal);
        n = NULL;
      }
    }
  }
}

/*
This is a recursive function that performs an in-order traversal of the binary search tree rooted at n, and 
inserts each node's value into the global arrStorage array n->occurrences times, where n->occurrences is the 
number of times the value appears in the input array. The function first recursively traverses the left subtree 
of n, then inserts n->val n->occurrences times into arrStorage, and finally recursively traverses the right 
subtree of n. After inserting the value of n and its subtrees, the function also frees the memory allocated for the node.
*/
static void inOrderInsert(Node *n) {
  if (n->left != NULL) {
    inOrderInsert(n->left);
  }
  for (int i = 0; i < n->occurrences; i += 1) {
    arrStorage[index] = n->val;
    index += 1;
  }
  if (n->right != NULL) {
    inOrderInsert(n->right);
  }
  free(n);
}
