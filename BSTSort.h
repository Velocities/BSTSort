#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
  int val;
  unsigned int occurrences;
  struct Node *left;
  struct Node *right;
} Node;

void BSTSort(int arr[], int size);

void insert(Node *n, int insertionVal);

void inOrderInsert(Node *n);

Node* makeNode(int value);
