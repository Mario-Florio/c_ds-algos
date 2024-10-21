#include "node.h"
#include "../../common.h"

typedef BinarySearchTree_Node Node;

void binarySearchTree_node_init(Node* pnode) {
    pnode->val = 0;
    pnode->left = NULL;
    pnode->right = NULL;
    pnode->count = 1;
}

void binarySearchTree_node_setVal(Node* pnode, int val) {
    pnode->val = val;
}

void binarySearchTree_node_reset(Node* pnode) {
    binarySearchTree_node_init(pnode);
}