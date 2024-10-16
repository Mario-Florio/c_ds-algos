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
    return 1;
}

void linkedList_add(LinkedList* plist, int idx, int val) {}

int linkedList_remove(LinkedList* plist, int idx) {
    return 1;
}

void linkedList_push(LinkedList* plist, int val) {}

int linkedList_pop(LinkedList* plist) {
    return 1;
}

void linkedList_shift(LinkedList* plist, int val) {}

int linkedList_unshift(LinkedList* plist) {
    return 1;
}
