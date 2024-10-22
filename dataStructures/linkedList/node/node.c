#include "node.h"
#include "../../../common.h"

typedef LinkedList_Node Node;

void linkedList_node_init(Node* pnode) {
    pnode->val = 0;
    pnode->next = NULL;
    pnode->prev = NULL;
}

void linkedList_node_setVal(Node* pnode, int val) {
    pnode->val = val;
}

void linkedList_node_link(Node* phead, Node* ptail) {
    phead->next = ptail;
    ptail->prev = phead;
}

void linkedList_node_reset(Node* pnode) {
    linkedList_node_init(pnode);
}