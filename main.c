#include "common.h"
#include "testSuites/testSuites.h"
#include "components/menu/menu.h"
#include "__utils__/arrContains/arrContains.h"

void menu();

int main(int argc, char* argv[]) {
    if (arrContains(argc, argv, "test")) {
        runTestSuites(argc, argv);
    } else {
        menu();
    }

    return 1;
}
