#include "common.h"
#include "node/testSuites/testSuites.h"
#include "linkedList/testSuites/testSuites.h"
#include "stack/testSuites/testSuites.h"
#include "queue/testSuites/testSuites.h"

int main(int argc, char* argv[]) {
    int runAll = argc == 1;
    int runNode = 0;
    int runLinkedList = 0;
    int runStack = 0;
    int runQueue = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "node") == 0) runNode = 1;
        if (strcmp(argv[i], "linkedlist") == 0) runLinkedList = 1;
        if (strcmp(argv[i], "stack") == 0) runStack = 1;
        if (strcmp(argv[i], "queue") == 0) runQueue = 1;
    }

    if (runAll || runNode) node_testSuites();
    if (runAll || runLinkedList) linkedList_testSuites();
    if (runAll || runStack) stack_testSuites();
    if (runAll || runQueue) queue_testSuites();

    return 1;
}
