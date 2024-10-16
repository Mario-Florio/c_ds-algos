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

    int headVal = list.head->val;
    it("Returns head if idx is less than zero", headVal == 1);

    int tailVal = list.tail->val;
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
    int headVal = list.head->val;
    it("Adds to head if index is less than zero", headVal == -6);

    linkedList_add(&list, 15, 6);
    int tailVal = list.tail->val;
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

    int headVal = list.head->val;
    it("Removes head if index is less than zero", linkedList_remove(&list, -5) == headVal);

    int tailVal = list.tail->val;
    it("Removes tail if index is less than zero", linkedList_remove(&list, 13) == tailVal);

    linkedList_reset(&list);
}

void linkedList_pushTests() {
    LinkedList list;
    linkedList_init(&list);

    int countIsAccurate = 1;
    int valueIsAccurate = 1;

    linkedList_push(&list, 1);
    countIsAccurate = list.count == 1;
    valueIsAccurate = list.tail->val == 1;
    linkedList_push(&list, 2);
    countIsAccurate = list.count == 2;
    valueIsAccurate = list.tail->val == 2;
    linkedList_push(&list, 3);
    countIsAccurate = list.count == 3;
    valueIsAccurate = list.tail->val == 3;
    linkedList_push(&list, 4);
    countIsAccurate = list.count == 4;
    valueIsAccurate = list.tail->val == 4;
    linkedList_push(&list, 5);
    countIsAccurate = list.count == 5;
    valueIsAccurate = list.tail->val == 5;
    linkedList_push(&list, 6);
    countIsAccurate = list.count == 6;
    valueIsAccurate = list.tail->val == 6;
    linkedList_push(&list, 7);
    countIsAccurate = list.count == 7;
    valueIsAccurate = list.tail->val == 7;
    linkedList_push(&list, 8);
    countIsAccurate = list.count == 8;
    valueIsAccurate = list.tail->val == 8;
    linkedList_push(&list, 9);
    countIsAccurate = list.count == 9;
    valueIsAccurate = list.tail->val == 9;

    it("Adds to end of list", countIsAccurate);
    it("Updates count", valueIsAccurate);

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

    it("Adds to beginning", list.head->val == 0);
    it("Updates count", list.count == 10);

    linkedList_reset(&list);
}

void linkedList_unshiftTests() {
    LinkedList list;
    linkedList_init(&list);
    fillList(&list, 9);

    int val = linkedList_unshift(&list);

    it("Removes first node", val == 1);
    it("Updates head", list.head->val == 2);
    it("Updates count", list.count == 8);

    linkedList_reset(&list);
}

// UTILS
void fillList(LinkedList* plist, int amount) {
    for (int i = 0; i < amount; i++) {
        linkedList_push(plist, i+1);
    }
}
