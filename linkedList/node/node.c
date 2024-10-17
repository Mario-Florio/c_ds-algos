#include "node.h"
#include "../../common.h"

void node_init(Node* pnode) {
    pnode->val = 0;
    pnode->next = NULL;
    pnode->prev = NULL;
}

void node_setVal(Node* pnode, int val) {
    pnode->val = val;
}

void node_link(Node* phead, Node* ptail) {
    phead->next = ptail;
    ptail->prev = phead;
}

void node_reset(Node* pnode) {
    node_init(pnode);
}