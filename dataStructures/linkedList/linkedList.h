#ifndef datastructures_linkedlist_linkedlist_h
#define datastructures_linkedlist_linkedlist_h

#include "node/node.h"

typedef struct {
    LinkedList_Node* head;
    LinkedList_Node* tail;
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