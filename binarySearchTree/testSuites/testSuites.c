#include "../../test/test.h"
#include "../binarySearchTree.h"

typedef BinarySearchTree_Node Node;

static void binarySearchTree_insertTests();
static void binarySearchTree_containsTests();

void binarySearchTree_testSuites() {
    printf("====BINARY SEARCH TREE=====\n\n");
    suite("Insert:", binarySearchTree_insertTests);
    suite("Contains:", binarySearchTree_containsTests);
    printf("\n");
}

static void binarySearchTree_insertTests() {
    BinarySearchTree tree;
    BinarySearchTree* ptree = &tree;
    binarySearchTree_init(ptree);

    binarySearchTree_insert(ptree, 4);
    binarySearchTree_insert(ptree, 2);
    binarySearchTree_insert(ptree, 5);
    binarySearchTree_insert(ptree, 1);
    binarySearchTree_insert(ptree, 3);
    binarySearchTree_insert(ptree, 1);

    int isValidBST = 0;
    it("Creates a valid binary search tree", isValidBST);

    int count = tree.count ? tree.count : -1;
    it("Updates count", count == 6);

    int nodeCount = 0;
    it("Increments node count if inserted value is equivalent", nodeCount == 2);

    binarySearchTree_reset(ptree);
}

static void binarySearchTree_containsTests() {
    BinarySearchTree tree;
    BinarySearchTree* ptree = &tree;
    binarySearchTree_init(ptree);

    binarySearchTree_insert(ptree, 4);
    binarySearchTree_insert(ptree, 2);
    binarySearchTree_insert(ptree, 5);
    binarySearchTree_insert(ptree, 1);
    binarySearchTree_insert(ptree, 3);
    binarySearchTree_insert(ptree, 1);

    it("Returns truthy if tree contains valiue", binarySearchTree_contains(ptree, 1));
    it("Returns falsy if tree doesn't contains valiue", binarySearchTree_contains(ptree, 7) == 0);

    binarySearchTree_reset(ptree);
}
