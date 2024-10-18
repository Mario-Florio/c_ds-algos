#include "../../../test/test.h"
#include "tests.h"

static void fillList(LinkedList* plist, int amount);

void abstract_linkedList_accessTests(LinkedList* plist, int (*linkedList_access)(LinkedList* plist, int idx)) {
    linkedList_init(plist);
    fillList(plist, 9);

    int val = linkedList_access(plist, 4);

    it("Accesses accurate index", val == 5);

    int headVal = plist->head ? plist->head->val : 0;
    it("Returns head if idx is less than zero", headVal == 1);

    int tailVal = plist->tail ? plist->tail->val : 0;
    it("Returns tail if idx is greater than count", tailVal == 9);

    linkedList_reset(plist);
}

void abstract_linkedList_addTests(LinkedList* plist, void (*linkedList_add)(LinkedList* plist, int idx, int val)) {
    linkedList_init(plist);
    fillList(plist, 9);

    linkedList_add(plist, 6, 2);
    int val = linkedList_access(plist, 6);

    it("Adds to accurate index", val == 2);
    it("Updates count", plist->count == 10);

    linkedList_add(plist, -5, -6);
    int headVal = plist->head ? plist->head->val : 0;
    it("Adds to head if index is less than zero", headVal == -6);

    linkedList_add(plist, 15, 6);
    int tailVal = plist->tail ? plist->tail->val : 0;
    it("Adds to tail if index is greater than count", tailVal == 6);

    linkedList_reset(plist);
}

void abstract_linkedList_removeTests(LinkedList* plist, int (*linkedList_remove)(LinkedList* plist, int idx)) {
    linkedList_init(plist);
    fillList(plist, 9);

    int val = linkedList_remove(plist, 3);

    it("Removes from accurate index", val == 4);
    it("Updates count", plist->count == 8);

    int headVal = plist->head ? plist->head->val : 0;
    it("Removes head if index is less than zero", linkedList_remove(plist, -5) == headVal);

    int tailVal = plist->tail ? plist->tail->val : 0;
    it("Removes tail if index is less than zero", linkedList_remove(plist, 13) == tailVal);

    linkedList_reset(plist);
}

void abstract_linkedList_pushTests(LinkedList* plist, void (*linkedList_push)(LinkedList* plist, int val)) {
    linkedList_init(plist);

    linkedList_push(plist, 1);
    linkedList_push(plist, 2);
    linkedList_push(plist, 3);
    linkedList_push(plist, 4);
    linkedList_push(plist, 5);
    linkedList_push(plist, 6);
    linkedList_push(plist, 7);
    linkedList_push(plist, 8);
    linkedList_push(plist, 9);

    int tailVal = plist->tail ? plist->tail->val : 0;
    it("Adds to end of list", tailVal == 9);
    it("Updates count", plist->count == 9);

    linkedList_reset(plist);
}

void abstract_linkedList_popTests(LinkedList* plist, int (*linkedList_pop)(LinkedList* plist)) {
    linkedList_init(plist);
    fillList(plist, 9);

    int poppedVal = linkedList_pop(plist);
    it("Removes last node", poppedVal == 9);
    it("Updates count", plist->count == 8);

    linkedList_reset(plist);
}

void abstract_linkedList_shiftTests(LinkedList* plist, void (*linkedList_shift)(LinkedList* plist, int val)) {
    linkedList_init(plist);
    fillList(plist, 9);

    linkedList_shift(plist, 0);

    int headVal = plist->head ? plist->head->val : -1;
    it("Adds to beginning", headVal == 0);
    it("Updates count", plist->count == 10);

    linkedList_reset(plist);
}

void abstract_linkedList_unshiftTests(LinkedList* plist, int (*linkedList_unshift)(LinkedList* plist)) {
    linkedList_init(plist);
    fillList(plist, 9);

    int val = linkedList_unshift(plist);

    int headVal = plist->head ? plist->head->val : 0;
    it("Removes first node", val == 1);
    it("Updates head", headVal == 2);
    it("Updates count", plist->count == 8);

    linkedList_reset(plist);
}

// UTILS
static void fillList(LinkedList* plist, int amount) {
    for (int i = 0; i < amount; i++) {
        linkedList_push(plist, i+1);
    }
}
