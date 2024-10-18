#include "../../test/test.h"
#include "tests/tests.h"
#include "../linkedList.h"

static void linkedList_accessTests();
static void linkedList_addTests();
static void linkedList_removeTests();
static void linkedList_pushTests();
static void linkedList_popTests();
static void linkedList_shiftTests();
static void linkedList_unshiftTests();

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

static void linkedList_accessTests() {
    LinkedList list;
    abstract_linkedList_accessTests(&list, linkedList_access);
}

static void linkedList_addTests() {
    LinkedList list;
    abstract_linkedList_addTests(&list, linkedList_add);
}

static void linkedList_removeTests() {
    LinkedList list;
    abstract_linkedList_removeTests(&list, linkedList_remove);
}

static void linkedList_pushTests() {
    LinkedList list;
    abstract_linkedList_pushTests(&list, linkedList_push);
}

static void linkedList_popTests() {
    LinkedList list;
    abstract_linkedList_popTests(&list, linkedList_pop);
}

static void linkedList_shiftTests() {
    LinkedList list;
    abstract_linkedList_shiftTests(&list, linkedList_shift);
}

static void linkedList_unshiftTests() {
    LinkedList list;
    abstract_linkedList_unshiftTests(&list, linkedList_unshift);
}
