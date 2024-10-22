#include "../../../test/test.h"
#include "../stack.h"
#include "../../linkedList/testSuites/tests/tests.h"

static void stack_accessTests();
static void stack_peekTests();
static void stack_pushTests();
static void stack_popTests();

void stack_testSuites() {
    printf("==========STACK===========\n\n");
    suite("Access:", stack_accessTests);
    suite("Peek:", stack_peekTests);
    suite("Push:", stack_pushTests);
    suite("Pop:", stack_popTests);
    printf("\n");
}

static void stack_accessTests() {
    Stack stack;
    abstract_linkedList_accessTests(&stack, stack_access);
}

static void stack_peekTests() {
    Stack stack;
    Stack* pstack = &stack;
    stack_init(pstack);
    for (int i = 1; i < 10; i++) stack_push(pstack, i);

    it("Returns tail", stack_peek(pstack) == 9);

    stack_reset(pstack);
}

static void stack_pushTests() {
    Stack stack;
    abstract_linkedList_pushTests(&stack, stack_push);
}

static void stack_popTests() {
    Stack stack;
    abstract_linkedList_popTests(&stack, stack_pop);
}
