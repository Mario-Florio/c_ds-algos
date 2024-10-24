#include "../../common.h"
#include "linkedList.h"

typedef LinkedList_Node Node;

void linkedList_init(LinkedList* plist) {
    plist->head = NULL;
    plist->tail = NULL;
    plist->count = 0;
}

void linkedList_reset(LinkedList* plist) {
    Node* curr = plist->head;
    for (int i = 0; i < plist->count; i++) {
        Node* next = curr->next;
        linkedList_node_reset(curr);
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
    int val = curr ? curr->val : -1;
    return val;
}

void linkedList_add(LinkedList* plist, int idx, int val) {
    if (idx <= 0) return linkedList_shift(plist, val);
    if (idx >= plist->count) return linkedList_push(plist, val);

    Node* pnode = (Node*)malloc(sizeof(Node));
    linkedList_node_init(pnode);
    linkedList_node_setVal(pnode, val);

    if (idx > (plist->count / 2)) {
        Node* curr = plist->tail;
        for (int i = plist->count; i > idx+1; i--) {
            curr = curr->prev;
        }
        Node* temp = curr->prev;
        curr->prev = pnode;
        pnode->next = curr;
        pnode->prev = temp;
        temp->next = pnode;
    } else {
        Node* curr = plist->head;
        for (int i = 0; i < idx-1 && plist->count; i++) {
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = pnode;
        pnode->prev = curr;
        pnode->next = temp;
        temp-> prev = pnode;
    }
    plist->count++;
}

int linkedList_remove(LinkedList* plist, int idx) {
    if (!plist->count) return -1;
    if (idx <= 0) return linkedList_unshift(plist);
    if (idx >= plist->count) return linkedList_pop(plist);

    Node* targ;
    if (idx > (plist->count / 2)) {
        if (!plist->tail) return -1;
        Node* curr = plist->tail;
        for (int i = plist->count; i > idx+2; i--) {
            curr = curr->prev;
        }
        targ = curr->prev;

        curr->prev = targ->prev;
        curr->prev->next = curr;

    } else {
        if (!plist->head) return -1;
        Node* curr = plist->head;
        for (int i = 0; i < idx-1; i++) {
            curr = curr->next;
        }
        targ = curr->next;

        curr->next = targ->next;
        curr->next->prev = curr;
    }
    plist->count--;

    if (!targ) return -1;
    int val = targ->val;

    linkedList_node_reset(targ);
    free(targ);

    return val;
}

void linkedList_push(LinkedList* plist, int val) {
    Node* pnode = (Node*)malloc(sizeof(Node));
    linkedList_node_init(pnode);
    linkedList_node_setVal(pnode, val);

    if (plist->head == NULL) {
        plist->head = pnode;
        plist->tail = pnode;
    } else {
        Node* oldTail = plist->tail;
        linkedList_node_link(oldTail, pnode);
        plist->tail = pnode;
    }
    plist->count++;
}

int linkedList_pop(LinkedList* plist) {
    if (!plist->tail || !plist->count) return -1;
    Node* tail = plist->tail;
    int val = tail->val;
    Node* curr = tail->prev;

    linkedList_node_reset(tail);
    free(tail);

    if (!!curr) curr->next = NULL;
    plist->tail = curr;
    plist->count--;

    return val;
}

void linkedList_shift(LinkedList* plist, int val) {
    Node* pnode = (Node*)malloc(sizeof(Node));
    linkedList_node_init(pnode);
    linkedList_node_setVal(pnode, val);
    
    if (plist->head == NULL) {
        plist->head = pnode;
        plist->tail = pnode;
    } else {
        Node* oldHead = plist->head;
        linkedList_node_link(pnode, oldHead);
        plist->head = pnode;
    }
    plist->count++;
}

int linkedList_unshift(LinkedList* plist) {
    if (!plist->head || !plist->count) return -1;
    Node* head = plist->head;
    int val = head->val;
    Node* curr = head->next;

    linkedList_node_reset(head);
    free(head);

    if (!!curr) curr->prev = NULL;
    plist->head = curr;
    plist->count--;

    return val;
}

void linkedList_print(LinkedList* plist) {
    if (!plist->head || !plist->count) return;
    printf("\n");

    Node* curr = plist->head;
    while (curr->next) {
        printf("%d <-> ", curr->val);
        curr = curr->next;
    }
    printf("%d\n", curr->val);
}
