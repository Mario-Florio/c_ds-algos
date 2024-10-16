#include "node.h"

void node_init(Node* pnode) {
    pnode->val = 0;
    pnode->next = NULL;
    pnode->prev = NULL;
}

void node_setVal(Node* pnode, int val) {
    pnode->val = val;
}

void node_link(Node* head, Node* tail) {

}

void node_reset(Node* pnode) {

}