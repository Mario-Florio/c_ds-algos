#ifndef c_dsalgos_binarysearchtree_node_node_h
#define c_dsalgos_binarysearchtree_node_node_h

typedef struct BinarySearchTree_Node {
    int val;
    struct BinarySearchTree_Node* next;
    struct BinarySearchTree_Node* prev;
    int count;
} BinarySearchTree_Node;

void binarySearchTree_node_init(BinarySearchTree_Node* pnode);
void binarySearchTree_node_setVal(BinarySearchTree_Node* pnode, int val);
void binarySearchTree_node_link(BinarySearchTree_Node* head, BinarySearchTree_Node* tail);
void binarySearchTree_node_reset(BinarySearchTree_Node* pnode);

#endif