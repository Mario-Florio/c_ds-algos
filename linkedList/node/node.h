#ifndef c_dsalgos_linkedlist_node_node_h
#define c_dsalgos_linkedlist_node_node_h

typedef struct LinkedList_Node {
    int val;
    struct LinkedList_Node* next;
    struct LinkedList_Node* prev;
} LinkedList_Node;

void linkedList_node_init(LinkedList_Node* pnode);
void linkedList_node_setVal(LinkedList_Node* pnode, int val);
void linkedList_node_link(LinkedList_Node* head, LinkedList_Node* tail);
void linkedList_node_reset(LinkedList_Node* pnode);

#endif