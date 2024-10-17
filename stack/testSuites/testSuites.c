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
    abstract_linkedList_accessTests(&stack, stack_access);
}

void stack_pushTests() {
    Stack stack;
    abstract_linkedList_pushTests(&stack, stack_push);
}

void stack_popTests() {
    Stack stack;
    abstract_linkedList_popTests(&stack, stack_pop);
}
