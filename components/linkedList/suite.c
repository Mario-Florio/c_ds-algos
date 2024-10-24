#include "../../common.h"
#include "../../__utils__/arrContains/arrContains.h"
#include "../../__utils__/trimString/trimString.h"
#include "../../dataStructures/linkedList/linkedList.h"
#include "args.h"
#include "methods/methods.h"

static void getInput(LinkedList* plist);

void linkedList_suite() {
    LinkedList list;
    LinkedList* plist = &list;
    linkedList_init(plist);

    printf("Linked List %p initialized.\n\n", plist);
    getInput(plist);

    linkedList_reset(plist);
}

static void getInput(LinkedList* plist) {
    printf("What would you like to do?\n");
    printf("    1. Access\n");
    printf("    2. Add\n");
    printf("    3. Remove\n");
    printf("    4. Push\n");
    printf("    5. Pop\n");
    printf("    6. Shift\n");
    printf("    7. Unshift\n");
    printf("    8. Reset\n");
    printf("    9. Print\n");
    printf("    10. Return to Menu");
    printf("\n");

    char line[256];

    if (fgets(line, sizeof line, stdin) != NULL) {
        trimString(line);

        int accessArgsSize = sizeof(ACCESS_ARGS) / sizeof(ACCESS_ARGS[0]);
        int addArgsSize = sizeof(ADD_ARGS) / sizeof(ADD_ARGS[0]);
        int removeArgsSize = sizeof(REMOVE_ARGS) / sizeof(REMOVE_ARGS[0]);
        int pushArgsSize = sizeof(PUSH_ARGS) / sizeof(PUSH_ARGS[0]);
        int popArgsSize = sizeof(POP_ARGS) / sizeof(POP_ARGS[0]);
        int shiftArgsSize = sizeof(SHIFT_ARGS) / sizeof(SHIFT_ARGS[0]);
        int unshiftArgsSize = sizeof(UNSHIFT_ARGS) / sizeof(UNSHIFT_ARGS[0]);
        int resetArgsSize = sizeof(RESET_ARGS) / sizeof(RESET_ARGS[0]);
        int printArgsSize = sizeof(PRINT_ARGS) / sizeof(PRINT_ARGS[0]);
        int returnArgsSize = sizeof(RETURN_ARGS) / sizeof(RETURN_ARGS[0]);

        if (arrContains(accessArgsSize, ACCESS_ARGS, line)) {
            linkedList_access_method(plist);
        } else if (arrContains(addArgsSize, ADD_ARGS, line)) {
            linkedList_add_method(plist);
        } else if (arrContains(removeArgsSize, REMOVE_ARGS, line)) {
            linkedList_remove_method(plist);
        } else if (arrContains(pushArgsSize, PUSH_ARGS, line)) {
            linkedList_push_method(plist);
        } else if (arrContains(popArgsSize, POP_ARGS, line)) {
            linkedList_pop_method(plist);
        } else if (arrContains(shiftArgsSize, SHIFT_ARGS, line)) {
            linkedList_shift_method(plist);
        } else if (arrContains(unshiftArgsSize, UNSHIFT_ARGS, line)) {
            linkedList_unshift_method(plist);
        } else if (arrContains(resetArgsSize, RESET_ARGS, line)) {
            linkedList_reset_method(plist);
        } else if (arrContains(printArgsSize, PRINT_ARGS, line)) {
            linkedList_print_method(plist);
        } else if (arrContains(returnArgsSize, RETURN_ARGS, line)) {
            return;
        } else {
            printf("\nPlease choose a valid option\n\n");
        }

        getInput(plist);
    }
}
