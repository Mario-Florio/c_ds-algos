#include "../../common.h"
#include "tests/tests.h"
#include "../linkedList.h"

void linkedList_accessTests();
void linkedList_addTests();
void linkedList_removeTests();
void linkedList_pushTests();
void linkedList_popTests();
void linkedList_shiftTests();
void linkedList_unshiftTests();

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
    abstract_linkedList_accessTests(&list, linkedList_access);
}

void linkedList_addTests() {
    LinkedList list;
    abstract_linkedList_addTests(&list, linkedList_add);
}

void linkedList_removeTests() {
    LinkedList list;
    abstract_linkedList_removeTests(&list, linkedList_remove);
}

void linkedList_pushTests() {
    LinkedList list;
    abstract_linkedList_pushTests(&list, linkedList_push);
}

void linkedList_popTests() {
    LinkedList list;
    abstract_linkedList_popTests(&list, linkedList_pop);
}

void linkedList_shiftTests() {
    LinkedList list;
    abstract_linkedList_shiftTests(&list, linkedList_shift);
}

void linkedList_unshiftTests() {
    LinkedList list;
    abstract_linkedList_unshiftTests(&list, linkedList_unshift);
}
