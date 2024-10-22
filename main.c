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
        if (
            strcmp(line, "Linked List") == 0 ||
            strcmp(line, "1") == 0 ||
            strcmp(line, "ll") == 0
        ) printf("ll\n");
        if (
            strcmp(line, "Stack") == 0 ||
            strcmp(line, "2") == 0
        ) printf("s\n");
        if (
            strcmp(line, "Queue") == 0 ||
            strcmp(line, "3") == 0
        ) printf("q\n");
                if (
            strcmp(line, "Binary Search Tree") == 0 ||
            strcmp(line, "4") == 0 ||
            strcmp(line, "bst") == 0
        ) printf("bst\n");
    }
}
