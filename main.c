#include "common.h"
#include "testSuites/testSuites.h"
#include "__utils__/arrContains/arrContains.h"
#include "__utils__/trimString/trimString.h"

void menu();

int main(int argc, char* argv[]) {
    if (arrContains(argc, argv, "test")) {
        runTestSuites(argc, argv);
    } else {
        menu();
    }

    return 1;
}

void menu() {
    printf("\nWelcome to Data Structures.\n\n");
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
        if (arrContains(linkedListArgsSize, linkedListArgs, line)) printf("ll\n");

        char* stackArgs[] = { "Stack", "2" };
        int stackArgsSize = sizeof(stackArgs) / sizeof(stackArgs[0]);
        if (arrContains(stackArgsSize, stackArgs, line)) printf("s\n");

        char* queueArgs[] = { "Queue", "3" };
        int queueArgsSize = sizeof(queueArgs) / sizeof(queueArgs[0]);
        if (arrContains(queueArgsSize, queueArgs, line)) printf("q\n");

        char* binarySearchTreeArgs[] = { "Binary Search Tree", "4", "bst" };
        int binarySearchTreeArgsSize = sizeof(binarySearchTreeArgs) / sizeof(binarySearchTreeArgs[0]);
        if (arrContains(binarySearchTreeArgsSize, binarySearchTreeArgs, line)) printf("bst\n");
    }
}
