#include "testSuites.h"

void stack_accessTests();
void stack_pushTests();
void stack_popTests();

void fillStack(Stack* pstack, int amount);

void stack_testSuites() {
    printf("==========STACK===========\n\n");
    suite("Access:", stack_accessTests);
    suite("Push:", stack_pushTests);
    suite("Pop:", stack_popTests);
    printf("\n");
}

void stack_accessTests() {
    Stack stack;
    stack_init(&stack);
    fillStack(&stack, 9);

    int val = stack_access(&stack, 4);

    it("Accesses accurate index", val == 5);

    int headVal = stack.head ? stack.head->val : 0;
    it("Returns head if idx is less than zero", headVal == 1);

    int tailVal = stack.tail ? stack.tail->val : 0;
    it("Returns tail if idx is greater than count", tailVal == 9);

    stack_reset(&stack);
}

void stack_pushTests() {
    Stack stack;
    Stack* pstack = &stack;
    stack_init(pstack);

    stack_push(pstack, 1);
    stack_push(pstack, 2);
    stack_push(pstack, 3);
    stack_push(pstack, 4);
    stack_push(pstack, 5);
    stack_push(pstack, 6);
    stack_push(pstack, 7);
    stack_push(pstack, 8);
    stack_push(pstack, 9);

    int tailVal = stack.tail ? stack.tail->val : 0;
    it("Adds to end of stack", tailVal == 9);

    int count = stack.count ? stack.count : -1;
    it("Updates count", count == 9);

    stack_reset(pstack);
}

void stack_popTests() {
    Stack stack;
    Stack* pstack = &stack;
    stack_init(pstack);
    fillStack(pstack, 9);

    int poppedVal = stack_pop(pstack);
    it("Removes last node", poppedVal == 9);

    int count = stack.count ? stack.count : -1;
    it("Updates count", count == 8);

    stack_reset(pstack);
}

// UTILS
void fillStack(Stack* pstack, int amount) {
    for (int i = 0; i < amount; i++) {
        stack_push(pstack, i+1);
    }
}
