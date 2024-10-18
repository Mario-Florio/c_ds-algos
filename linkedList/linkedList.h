#ifndef c_dsalgos_linkedlist_linkedlist_h
#define c_dsalgos_linkedlist_linkedlist_h

#include "node/node.h"

typedef struct {
    Node* head;
    Node* tail;
    int count;
} LinkedList;

void linkedList_init(LinkedList* plist);
void linkedList_reset(LinkedList* plist);

int linkedList_access(LinkedList* plist, int idx);

void linkedList_add(LinkedList* plist, int idx, int val);
int linkedList_remove(LinkedList* plist, int idx);

void linkedList_push(LinkedList* plist, int val);
int linkedList_pop(LinkedList* plist);

void linkedList_shift(LinkedList* plist, int val);
int linkedList_unshift(LinkedList* plist);

#endif