#ifndef c_dsalgos_linkedlist_node_node_h
#define c_dsalgos_linkedlist_node_node_h

typedef struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
} Node;

void node_init(Node* pnode);
void node_setVal(Node* pnode, int val);
void node_link(Node* head, Node* tail);
void node_reset(Node* pnode);

#endif