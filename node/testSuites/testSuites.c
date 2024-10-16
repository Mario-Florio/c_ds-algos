#include "testSuites.h"

void node_initTests();
void node_setValTests();
void node_linkTests();
void node_resetTests();

void node_testSuites() {
    printf("===========NODE===========\n\n");
    suite("Init:", node_initTests);
    suite("Set Value:", node_setValTests);
    suite("Link:", node_linkTests);
    suite("Reset:", node_resetTests);
}

void node_initTests() {
    Node node;
    node_init(&node);

    it("Initalizes value to zero", node.val == 0);
    it("Initalizes next to NULL", node.prev == NULL);
    it("Initalizes prev to NULL", node.prev == NULL);
}

void node_setValTests() {
    Node node;
    node_setVal(&node, 7);

    it("Sets accurate value", node.val == 7);
}

void node_linkTests() {
    Node head;
    head.val = 1;
    head.next = NULL;
    head.prev = NULL;

    Node tail;
    tail.val = 2;
    tail.next = NULL;
    tail.prev = NULL;

    node_link(&head, &tail);

    it("Links tail to head.next", head.next == &tail);
    it("Links head to tail.prev", tail.prev == &head);
}

void node_resetTests() {
    Node node;
    Node next;
    Node prev;
    node.val = 1;
    node.next = &next;
    node.prev = &prev;

    node_reset(&node);

    it("Resets value to 0", node.val == 0);
    it("Resets next to NULL", node.next == NULL);
    it("Resets prev to NULL", node.prev == NULL);
}