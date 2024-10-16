#include "common.h"
#include "node/testSuites/testSuites.h"
#include "linkedList/testSuites/testSuites.h"

int main(int argc, char* argv[]) {
    node_testSuites();
    linkedList_testSuites();

    return 1;
}
