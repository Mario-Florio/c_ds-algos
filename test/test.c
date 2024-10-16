#include "test.h"

void suite(char* name, void (*func)()) {
    int nameLength = strlen(name);
    for (int i = 0; i < nameLength; i++) {
        printf("%c", name[i]);
    }
    printf("\n");

    func();
}

void it(char* name, int condition) {

}
