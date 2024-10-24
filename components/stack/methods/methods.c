#include "../../../common.h"
#include "methods.h"

static void finish();

void stack_access_method(Stack* pstack) {
    printf("Index? ");
    int idx;
    scanf("%d", &idx);
    fgetc(stdin);

    int val = stack_access(pstack, idx);

    printf("\033[1;32m"); // green
    printf("\nStack %p[%d]: %d\n\n", pstack, idx, val);
    printf("\033[1;0m");
    finish();
}

void stack_push_method(Stack* pstack) {
    printf("Value? ");
    int val;
    scanf("%d", &val);
    fgetc(stdin);

    stack_push(pstack, val);

    printf("\033[1;32m"); // green
    printf("\nPushed %d to Stack %p.\n\n", val, pstack);
    printf("\033[1;0m");
    finish();
}

void stack_pop_method(Stack* pstack) {
    int val = linkedList_pop(pstack);

    printf("\033[1;32m"); // green
    printf("\nPopped %d from Stack %p.\n\n", val, pstack);
    printf("\033[1;0m");
    finish();
}

void stack_peek_method(Stack* pstack) {
    if (!pstack->tail) {
        printf("\nStack is empty.\n\n");
        finish();
        return;
    }
    printf("\nTop of stack: %d\n\n", pstack->tail->val);
    finish();
}

void stack_print_method(Stack* pstack) {
    printf("\n");
    printf("\033[1;32m"); // green
    printf("Stack %p\n", pstack);
    printf("Head: %p\n", pstack->head);
    printf("Tail: %p\n", pstack->tail);
    printf("Count: %d\n", pstack->count);
    linkedList_print(pstack);
    printf("\033[1;0m");
    printf("\n");
    finish();
}

void stack_reset_method(Stack* pstack) {
    printf("Are you sure? (y/n)");
    char confirm;
    scanf("%c", &confirm);

    if (confirm == 'y') {
        stack_reset(pstack);

        printf("\033[1;32m"); // green
        printf("\nStack %p has been reset.\n\n", pstack);
        printf("\033[1;0m");
        scanf("");
        fgetc(stdin);
    } else if (confirm == 'n') {
        printf("\n");
        fgetc(stdin);
        return;
    } else {
        fgetc(stdin);
        stack_reset_method(pstack);
    }
}

// UTILS
static void finish() {
    printf("Press enter\n");
    scanf("");
    fgetc(stdin);
}
