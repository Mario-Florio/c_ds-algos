#include "common.h"

void tests() {
    it("Passes", 1);
    it("Fails", 0);
}

int main(int argc, char* argv[]) {
    suite("Test Suite", tests);

    return 1;
}
