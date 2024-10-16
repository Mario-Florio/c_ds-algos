#include "linkedList.h"

void linkedList_init(LinkedList* plist) {
    plist->head = NULL;
    plist->tail = NULL;
    plist->count = 0;
}

void linkedList_reset(LinkedList* plist) {
    Node* curr = plist->head;
    for (int i = 0; i < plist->count; i++) {
        Node* next = curr->next;
        node_reset(curr);
        free(curr);
        curr = next;
    }
    linkedList_init(plist);
}

int linkedList_access(LinkedList* plist, int idx) {
    Node* curr = plist->head;
    for (int i = 0; i < idx && i < plist->count-1; i++) {
        curr = curr->next;
    }
    return curr->val;
}

void linkedList_add(LinkedList* plist, int idx, int val) {}

int linkedList_remove(LinkedList* plist, int idx) {
    return 1;
}

void linkedList_push(LinkedList* plist, int val) {
    Node* pnode = (Node*)malloc(sizeof(Node));
    node_init(pnode);
    node_setVal(pnode, val);

    if (plist->head == NULL) {
        plist->head = pnode;
        plist->tail = pnode;
    } else {
        Node* oldTail = plist->tail;
        node_link(oldTail, pnode);
        plist->tail = pnode;
    }
    plist->count++;
}

int linkedList_pop(LinkedList* plist) {
    Node* tail = plist->tail;
    int val = tail->val;
    Node* curr = tail->prev;

    node_reset(tail);
    free(tail);

    curr->next = NULL;
    plist->tail = curr;
    plist->count--;

    return val;
}

void linkedList_shift(LinkedList* plist, int val) {
    Node* pnode = (Node*)malloc(sizeof(Node));
    node_init(pnode);
    node_setVal(pnode, val);
    
    if (plist->head == NULL) {
        plist->head = pnode;
        plist->tail = pnode;
    } else {
        Node* oldHead = plist->head;
        node_link(pnode, oldHead);
        plist->head = pnode;
    }
    plist->count++;
}

int linkedList_unshift(LinkedList* plist) {
    return 1;
}
