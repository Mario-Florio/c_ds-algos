#include "node.h"
#include "../../common.h"

typedef BinarySearchTree_Node Node;

void binarySearchTree_node_init(Node* pnode) {
    pnode->val = 0;
    pnode->next = NULL;
    pnode->prev = NULL;
    pnode->count = 0;
}

void binarySearchTree_node_setVal(Node* pnode, int val) {
    pnode->val = val;
}

void binarySearchTree_node_link(Node* phead, Node* ptail) {
    phead->next = ptail;
    ptail->prev = phead;
}

void binarySearchTree_node_reset(Node* pnode) {
    binarySearchTree_node_init(pnode);
}