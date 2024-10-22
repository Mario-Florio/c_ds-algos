#include "common.h"
#include "testSuites/testSuites.h"

int main(int argc, char* argv[]) {
    if (argsContainsTest(argc, argv)) runTestSuites(argc, argv);

    return 1;
}
