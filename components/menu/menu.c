#include "../../common.h"
#include "../../__utils__/arrContains/arrContains.h"
#include "../../__utils__/trimString/trimString.h"
#include "args.h"
#include "../linkedList/suite.h"
#include "../stack/suite.h"
#include "../queue/suite.h"

static void getInput();

void menu() {
    printf("\nWelcome to Data Structures.\n");
    getInput();
}

static void getInput() {
    printf("\nWhich data structure would you like to use?\n");
    printf("    1. Linked List\n");
    printf("    2. Stack\n");
    printf("    3. Queue\n");
    printf("    4. Binary Search Tree\n");
    printf("    5. Exit");
    printf("\n");

    char line[256];

    if (fgets(line, sizeof line, stdin) != NULL) {
        trimString(line);

        int linkedListArgsSize = sizeof(LINKEDLIST_ARGS) / sizeof(LINKEDLIST_ARGS[0]);
        int stackArgsSize = sizeof(STACK_ARGS) / sizeof(STACK_ARGS[0]);
        int queueArgsSize = sizeof(QUEUE_ARGS) / sizeof(QUEUE_ARGS[0]);
        int binarySearchTreeArgsSize = sizeof(BINARYSEARCHTREE_ARGS) / sizeof(BINARYSEARCHTREE_ARGS[0]);
        int exitArgsSize = sizeof(EXIT_ARGS) / sizeof(EXIT_ARGS[0]);

        if (arrContains(linkedListArgsSize, LINKEDLIST_ARGS, line)) {
            linkedList_suite();

        } else if (arrContains(stackArgsSize, STACK_ARGS, line)) {
            stack_suite();

        } else if (arrContains(queueArgsSize, QUEUE_ARGS, line)) {
            queue_suite();

        } else if (arrContains(binarySearchTreeArgsSize, BINARYSEARCHTREE_ARGS, line)) {
            printf("bst\n");

        } else if (arrContains(exitArgsSize, EXIT_ARGS, line)) {
            printf("\nExiting...\n\n");
            return;
            
        } else {
            printf("\nPlease choose a valid option\n\n");
        }

        getInput();
    }
}
