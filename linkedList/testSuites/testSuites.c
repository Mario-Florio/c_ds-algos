#include "testSuites.h"

void linkedList_accessTests();
void linkedList_addTests();
void linkedList_removeTests();
void linkedList_pushTests();
void linkedList_popTests();
void linkedList_shiftTests();
void linkedList_unshiftTests();

void fillList(LinkedList* plist, int amount);

void linkedList_testSuites() {
    printf("=====LINKED LIST TESTS=====\n\n");
    suite("Access:", linkedList_accessTests);
    suite("Add:", linkedList_addTests);
    suite("Remove:", linkedList_removeTests);
    suite("Push:", linkedList_pushTests);
    suite("Pop:", linkedList_popTests);
    suite("Shift:", linkedList_shiftTests);
    suite("Unshift:", linkedList_unshiftTests);
    printf("\n");
}

void linkedList_accessTests() {
    LinkedList list;
    linkedList_init(&list);
    fillList(&list, 9);

    int val = linkedList_access(&list, 4);

    it("Accesses accurate index", val == 5);

    int headVal = list.head ? list.head->val : 0;
    it("Returns head if idx is less than zero", headVal == 1);

    int tailVal = list.tail ? list.tail->val : 0;
    it("Returns tail if idx is greater than count", tailVal == 9);

    linkedList_reset(&list);
}

void linkedList_addTests() {
    LinkedList list;
    linkedList_init(&list);
    fillList(&list, 9);

    linkedList_add(&list, 6, 2);
    int val = linkedList_access(&list, 6);

    it("Adds to accurate index", val == 2);
    it("Updates count", list.count == 10);

    linkedList_add(&list, -5, -6);
    int headVal = list.head ? list.head->val : 0;
    it("Adds to head if index is less than zero", headVal == -6);

    linkedList_add(&list, 15, 6);
    int tailVal = list.tail ? list.tail->val : 0;
    it("Adds to tail if index is greater than count", tailVal == 6);

    linkedList_reset(&list);
}

void linkedList_removeTests() {
    LinkedList list;
    linkedList_init(&list);
    fillList(&list, 9);

    int val = linkedList_remove(&list, 3);

    it("Removes from accurate index", val == 4);
    it("Updates count", list.count == 8);

    int headVal = list.head ? list.head->val : 0;
    it("Removes head if index is less than zero", linkedList_remove(&list, -5) == headVal);

    int tailVal = list.tail ? list.tail->val : 0;
    it("Removes tail if index is less than zero", linkedList_remove(&list, 13) == tailVal);

    linkedList_reset(&list);
}

void linkedList_pushTests() {
    LinkedList list;
    linkedList_init(&list);

    linkedList_push(&list, 1);
    linkedList_push(&list, 2);
    linkedList_push(&list, 3);
    linkedList_push(&list, 4);
    linkedList_push(&list, 5);
    linkedList_push(&list, 6);
    linkedList_push(&list, 7);
    linkedList_push(&list, 8);
    linkedList_push(&list, 9);

    int tailVal = list.tail ? list.tail->val : 0;
    it("Adds to end of list", tailVal == 9);
    it("Updates count", list.count == 9);

    linkedList_reset(&list);
}

void linkedList_popTests() {
    LinkedList list;
    linkedList_init(&list);
    fillList(&list, 9);

    int poppedVal = linkedList_pop(&list);
    it("Removes last node", poppedVal == 9);
    it("Updates count", list.count == 8);

    linkedList_reset(&list);
}

void linkedList_shiftTests() {
    LinkedList list;
    linkedList_init(&list);
    fillList(&list, 9);

    linkedList_shift(&list, 0);

    int headVal = list.head ? list.head->val : -1;
    it("Adds to beginning", headVal == 0);
    it("Updates count", list.count == 10);

    linkedList_reset(&list);
}

void linkedList_unshiftTests() {
    LinkedList list;
    linkedList_init(&list);
    fillList(&list, 9);

    int val = linkedList_unshift(&list);

    int headVal = list.head ? list.head->val : 0;
    it("Removes first node", val == 1);
    it("Updates head", headVal == 2);
    it("Updates count", list.count == 8);

    linkedList_reset(&list);
}

// UTILS
void fillList(LinkedList* plist, int amount) {
    for (int i = 0; i < amount; i++) {
        linkedList_push(plist, i+1);
    }
}
