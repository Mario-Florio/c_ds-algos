#include "common.h"

void tests() {
    printf("Tests run here\n");
}

int main(int argc, char* argv[]) {
    suite("Test Suite", tests);

    return 1;
}
