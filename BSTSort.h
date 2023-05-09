/*
Here we define a struct Node which represents a node in a binary search tree. 
Each node stores an integer value, the number of times the value occurs in the tree, and pointers to its left and right children.
*/
typedef struct Node {
  int val;
  unsigned int occurrences; // The reason we need this variable is due to the nature of a BST having no duplicate nodes
  struct Node *left;
  struct Node *right;
} Node;

void BSTSort(int arr[], int size);

void insert(Node *n, int insertionVal);

void inOrderInsert(Node *n);

Node* makeNode(int value);
