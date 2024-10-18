#include "../common.h"
#include "../linkedList/node/testSuites/testSuites.h"
#include "../linkedList/testSuites/testSuites.h"
#include "../stack/testSuites/testSuites.h"
#include "../queue/testSuites/testSuites.h"
#include "../binarySearchTree/node/testSuites/testSuites.h"
#include "../binarySearchTree/testSuites/testSuites.h"

void runTestSuites(int argc, char* argv[]) {
    int runAll = argc == 1;
    int runLinkedListNode = 0;
    int runLinkedList = 0;
    int runStack = 0;
    int runQueue = 0;
    int runBinarySearchTreeNode = 0;
    int runBinarySearchTree = 0;
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "linkedListNode") == 0) runLinkedListNode = 1;
        if (strcmp(argv[i], "linkedlist") == 0) runLinkedList = 1;
        if (strcmp(argv[i], "stack") == 0) runStack = 1;
        if (strcmp(argv[i], "queue") == 0) runQueue = 1;
        if (strcmp(argv[i], "binarySearchTreeNode") == 0) runBinarySearchTreeNode = 1;
        if (strcmp(argv[i], "binarySearchTree") == 0) runBinarySearchTree = 1;
    }

    if (runAll || runLinkedListNode) linkedList_node_testSuites();
    if (runAll || runLinkedList) linkedList_testSuites();
    if (runAll || runStack) stack_testSuites();
    if (runAll || runQueue) queue_testSuites();
    if (runAll || runBinarySearchTreeNode) binarySearchTree_node_testSuites();
    if (runAll || runBinarySearchTree) binarySearchTree_testSuites();
}
