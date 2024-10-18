#include "test.h"

static void printName(char* name);

void suite(char* name, void (*func)()) {
    int nameLength = strlen(name);
    for (int i = 0; i < nameLength; i++) {
        printf("%c", name[i]);
    }
    printf("\n");

    func();
}

void it(char* name, int condition) {
    if (condition) {
        printf("\033[1;32m"); // green
        printf("    ");
        printName(name);
        printf(" ✓\n");
    } else {
        printf("\033[1;31m"); // red
        printf("    ");
        printName(name);
        printf(" ✗\n");
    }

    printf("\033[1;0m");
}

static void printName(char* name) {
    int nameLength = strlen(name);
    for (int i = 0; i < nameLength; i++) {
        printf("%c", name[i]);
    }
}
