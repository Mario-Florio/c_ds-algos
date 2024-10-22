#include "../../common.h"
#include "../../__utils__/arrContains/arrContains.h"
#include "../../__utils__/trimString/trimString.h"

static void getInput();

void menu() {
    printf("\nWelcome to Data Structures.\n\n");
    getInput();
}

static void getInput() {
    printf("Which data structure would you like to use?\n");
    printf("    1. Linked List\n");
    printf("    2. Stack\n");
    printf("    3. Queue\n");
    printf("    4. Binary Search Tree\n");
    printf("\n");

    char line[256];

    if (fgets(line, sizeof line, stdin) != NULL) {
        trimString(line);

        char* linkedListArgs[] = { "Linked List", "1", "ll" };
        int linkedListArgsSize = sizeof(linkedListArgs) / sizeof(linkedListArgs[0]);

        char* stackArgs[] = { "Stack", "2" };
        int stackArgsSize = sizeof(stackArgs) / sizeof(stackArgs[0]);

        char* queueArgs[] = { "Queue", "3" };
        int queueArgsSize = sizeof(queueArgs) / sizeof(queueArgs[0]);

        char* binarySearchTreeArgs[] = { "Binary Search Tree", "4", "bst" };
        int binarySearchTreeArgsSize = sizeof(binarySearchTreeArgs) / sizeof(binarySearchTreeArgs[0]);

        if (arrContains(linkedListArgsSize, linkedListArgs, line)) printf("ll\n");

        else if (arrContains(stackArgsSize, stackArgs, line)) printf("s\n");

        else if (arrContains(queueArgsSize, queueArgs, line)) printf("q\n");

        else if (arrContains(binarySearchTreeArgsSize, binarySearchTreeArgs, line)) printf("bst\n");

        else {
            printf("\nPlease choose a valid option\n\n");
            getInput();
        }
    }
}
