#include "stack.h"

void stack_init(Stack* pstack) {
    linkedList_init(pstack);
}

void stack_reset(Stack* pstack) {
    linkedList_reset(pstack);
}

int stack_access(Stack* pstack, int idx) {
    return linkedList_access(pstack, idx);
}

int stack_peek(Stack* pstack) {
    return 1;
}

void stack_push(Stack* pstack, int val) {
    linkedList_push(pstack, val);
}

int stack_pop(Stack* pstack) {
    return linkedList_pop(pstack);
};
