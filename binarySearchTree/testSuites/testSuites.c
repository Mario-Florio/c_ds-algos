#include "../../test/test.h"
#include "../binarySearchTree.h"

static void binarySearchTree_insertTests();
static void binarySearchTree_findTests();
static void binarySearchTree_containsTests();

void binarySearchTree_testSuites() {
    printf("====BINARY SEARCH TREE=====\n\n");
    suite("Insert:", binarySearchTree_insertTests);
    suite("Find:", binarySearchTree_findTests);
    suite("Contains:", binarySearchTree_containsTests);
    printf("\n");
}

static void binarySearchTree_insertTests() {}
static void binarySearchTree_findTests() {}
static void binarySearchTree_containsTests() {}
