#include "../../common.h"
#include "../../__utils__/arrContains/arrContains.h"
#include "../../__utils__/trimString/trimString.h"
#include "../../dataStructures/stack/stack.h"
#include "args.h"
#include "methods/methods.h"

static void getInput(Stack* pstack);

void stack_suite() {
    Stack stack;
    Stack* pstack = &stack;
    stack_init(pstack);

    printf("Stack %p initialized.\n\n", pstack);
    getInput(pstack);

    stack_reset(pstack);
}

static void getInput(Stack* pstack) {
    printf("What would you like to do?\n");
    printf("    1. Access\n");
    printf("    2. Push\n");
    printf("    3. Pop\n");
    printf("    4. Peek\n");
    printf("    5. Reset\n");
    printf("\n");

    char line[256];

    if (fgets(line, sizeof line, stdin) != NULL) {
        trimString(line);

        int accessArgsSize = sizeof(ACCESS_ARGS) / sizeof(ACCESS_ARGS[0]);
        int pushArgsSize = sizeof(PUSH_ARGS) / sizeof(PUSH_ARGS[0]);
        int popArgsSize = sizeof(POP_ARGS) / sizeof(POP_ARGS[0]);
        int peekArgsSize = sizeof(PEEK_ARGS) / sizeof(PEEK_ARGS[0]);
        int resetArgsSize = sizeof(RESET_ARGS) / sizeof(RESET_ARGS[0]);

        if (arrContains(accessArgsSize, ACCESS_ARGS, line)) {
            stack_access_method(pstack);
        } else if (arrContains(pushArgsSize, PUSH_ARGS, line)) {
            stack_push_method(pstack);
        } else if (arrContains(popArgsSize, POP_ARGS, line)) {
            stack_pop_method(pstack);
        } else if (arrContains(peekArgsSize, PEEK_ARGS, line)) {
            stack_peek_method(pstack);
        } else if (arrContains(resetArgsSize, RESET_ARGS, line)) {
            stack_reset_method(pstack);
        } else {
            printf("\nPlease choose a valid option\n\n");
        }

        getInput(pstack);
    }
}
