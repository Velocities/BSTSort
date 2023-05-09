#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BSTSort.h"

static unsigned int index = 0;

static int* arrStorage;

Node* makeNode(int value) {
  Node *result = (Node *) malloc(sizeof(Node));
  result->val = value;
  result->occurrences = 1;
  result->left = NULL;
  result->right = NULL;
  return result;
}

void BSTSort(int arr[], int size) {
  Node *root = makeNode(arr[0]);
  for (int i = 1; i < size; i += 1) {
    insert(root, arr[i]);
  }
  // Input BST into array
  int index = 0;
  arrStorage = arr;
  inOrderInsert(root);
  index = 0;
}

void insert(Node *n, int insertionVal) {
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

void inOrderInsert(Node *n) {
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
