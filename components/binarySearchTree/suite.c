#include "../../common.h"
#include "../../__utils__/arrContains/arrContains.h"
#include "../../__utils__/trimString/trimString.h"
#include "../../dataStructures/binarySearchTree/binarySearchTree.h"
#include "args.h"
#include "methods/methods.h"

static void getInput(BinarySearchTree* ptree);

void binarySearchTree_suite() {
    BinarySearchTree tree;
    BinarySearchTree* ptree = &tree;
    binarySearchTree_init(ptree);

    printf("Binary Search Tree %p initialized.\n\n", ptree);
    getInput(ptree);

    binarySearchTree_reset(ptree);
}

static void getInput(BinarySearchTree* ptree) {
    printf("What would you like to do?\n");
    printf("    1. Insert\n");
    printf("    2. Contains\n");
    printf("    3. Reset\n");
    printf("    4. Return to Home\n");
    printf("\n");

    char line[256];

    if (fgets(line, sizeof line, stdin) != NULL) {
        trimString(line);

        int insertArgsSize = sizeof(INSERT_ARGS) / sizeof(INSERT_ARGS[0]);
        int containsArgsSize = sizeof(CONTAINS_ARGS) / sizeof(CONTAINS_ARGS[0]);
        int resetArgsSize = sizeof(RESET_ARGS) / sizeof(RESET_ARGS[0]);
        int returnArgsSize = sizeof(RETURN_ARGS) / sizeof(RETURN_ARGS[0]);

        if (arrContains(insertArgsSize, INSERT_ARGS, line)) {
            binarySearchTree_insert_method(ptree);

        } else if (arrContains(containsArgsSize, CONTAINS_ARGS, line)) {
            binarySearchTree_contains_method(ptree);

        } else if (arrContains(resetArgsSize, RESET_ARGS, line)) {
            binarySearchTree_reset_method(ptree);

        } else if (arrContains(returnArgsSize, RETURN_ARGS, line)) {
            binarySearchTree_reset_method(ptree);
            return;
            
        } else {
            printf("\nPlease choose a valid option\n\n");
        }

        getInput(ptree);
    }
}
