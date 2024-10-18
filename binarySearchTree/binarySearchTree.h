#ifndef c_dsalgos_binarysearchtree_binarysearchtree_h
#define c_dsalgos_binarysearchtree_binarysearchtree_h

#include "node/node.h"

typedef struct {
    BinarySearchTree_Node* root;
} BinarySearchTree;

void binarySearchTree_init(BinarySearchTree* ptree);
void binarySearchTree_reset(BinarySearchTree* ptree);

void binarySearchTree_insert(BinarySearchTree* ptree, int val);
int binarySearchTree_find(BinarySearchTree* ptree, int val);
int binarySearchTree_contains(BinarySearchTree* ptree, int val);

#endif