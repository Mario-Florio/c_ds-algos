#include "../../../test/test.h"
#include "../node.h"

typedef BinarySearchTree_Node Node;

static void node_initTests();
static void node_setValTests();
static void node_linkTests();
static void node_resetTests();

void binarySearchTree_node_testSuites() {
    printf("==BINARY SEARCH TREE NODE=\n\n");
    suite("Init:", node_initTests);
    suite("Set Value:", node_setValTests);
    suite("Link:", node_linkTests);
    suite("Reset:", node_resetTests);
    printf("\n");
}

static void node_initTests() {
    Node node;
    binarySearchTree_node_init(&node);

    it("Initalizes value to zero", node.val == 0);
    it("Initalizes next to NULL", node.prev == NULL);
    it("Initalizes prev to NULL", node.prev == NULL);
    it("Initalizes count to zero", node.count == 0);
}

static void node_setValTests() {
    Node node;
    binarySearchTree_node_setVal(&node, 7);

    it("Sets accurate value", node.val == 7);
}

static void node_linkTests() {
    Node head;
    head.val = 1;
    head.next = NULL;
    head.prev = NULL;

    Node tail;
    tail.val = 2;
    tail.next = NULL;
    tail.prev = NULL;

    binarySearchTree_node_link(&head, &tail);

    it("Links tail to head.next", head.next == &tail);
    it("Links head to tail.prev", tail.prev == &head);
}

static void node_resetTests() {
    Node node;
    Node next;
    Node prev;
    node.val = 1;
    node.next = &next;
    node.prev = &prev;

    binarySearchTree_node_reset(&node);

    it("Resets value to 0", node.val == 0);
    it("Resets next to NULL", node.next == NULL);
    it("Resets prev to NULL", node.prev == NULL);
}