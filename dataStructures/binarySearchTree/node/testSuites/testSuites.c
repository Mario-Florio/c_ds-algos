#include "../../../../test/test.h"
#include "../node.h"

typedef BinarySearchTree_Node Node;

static void node_initTests();
static void node_setValTests();
static void node_resetTests();

void binarySearchTree_node_testSuites() {
    printf("==BINARY SEARCH TREE NODE=\n\n");
    suite("Init:", node_initTests);
    suite("Set Value:", node_setValTests);
    suite("Reset:", node_resetTests);
    printf("\n");
}

static void node_initTests() {
    Node node;
    binarySearchTree_node_init(&node);

    it("Initalizes value to zero", node.val == 0);
    it("Initalizes right to NULL", node.left == NULL);
    it("Initalizes left to NULL", node.left == NULL);
    it("Initalizes count to 1", node.count == 1);
}

static void node_setValTests() {
    Node node;
    binarySearchTree_node_setVal(&node, 7);

    it("Sets accurate value", node.val == 7);
}

static void node_resetTests() {
    Node node;
    Node right;
    Node left;
    node.val = 1;
    node.right = &right;
    node.left = &left;

    binarySearchTree_node_reset(&node);

    it("Resets value to 0", node.val == 0);
    it("Resets right to NULL", node.right == NULL);
    it("Resets left to NULL", node.left == NULL);
}