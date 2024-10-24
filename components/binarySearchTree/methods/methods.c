#include "../../../common.h"
#include "methods.h"

static void finish();

void binarySearchTree_insert_method(BinarySearchTree* ptree) {
    printf("Value? ");
    int val;
    scanf("%d", &val);
    fgetc(stdin);

    binarySearchTree_insert(ptree, val);

    printf("\033[1;32m"); // green
    printf("\nInserted %d to Binary Search Tree %p.\n\n", val, ptree);
    printf("\033[1;0m");
    finish();
}
void binarySearchTree_contains_method(BinarySearchTree* ptree) {
    printf("Value? ");
    int val;
    scanf("%d", &val);
    fgetc(stdin);

    int contains = binarySearchTree_contains(ptree, val);
    printf("\n\n%d\n\n", contains);

    printf("\033[1;32m"); // green
    if (contains) printf("\nBinary Search Tree %p does contain %d.\n\n", ptree, val);
    else printf("\nBinary Search Tree %p does not contain %d.\n\n", ptree, val);
    printf("\033[1;0m");
    finish();
}

void binarySearchTree_reset_method(BinarySearchTree* ptree) {
    printf("Are you sure? (y/n)");
    char confirm;
    scanf("%c", &confirm);

    if (confirm == 'y') {
        binarySearchTree_reset(ptree);

        printf("\033[1;32m"); // green
        printf("\nBinary Search Tree %p has been reset.\n\n", ptree);
        printf("\033[1;0m");
        scanf("");
        fgetc(stdin);
    } else if (confirm == 'n') {
        printf("\n");
        fgetc(stdin);
        return;
    } else {
        fgetc(stdin);
        binarySearchTree_reset_method(ptree);
    }
}

// UTILS
static void finish() {
    printf("Press enter\n");
    scanf("");
    fgetc(stdin);
}
