#include "../../common.h"
#include "binarySearchTree.h"

typedef BinarySearchTree_Node Node;

static void freeTree(BinarySearchTree* ptree);

void binarySearchTree_init(BinarySearchTree* ptree) {
    ptree->root = NULL;
    ptree->count = 0;
}

void binarySearchTree_reset(BinarySearchTree* ptree) {
    freeTree(ptree);
    binarySearchTree_init(ptree);
}

void binarySearchTree_insert(BinarySearchTree* ptree, int val) {
    Node* pnode = (Node*)malloc(sizeof(Node));
    binarySearchTree_node_init(pnode);
    binarySearchTree_node_setVal(pnode, val);

    if (ptree->root == NULL) {
        ptree->root = pnode;
        ptree->count++;
        return;
    }

    Node* curr = ptree->root;
    while (1) {
        if (val == curr->val) {
            curr->count++;
            return;
        }
        if (val < curr->val) {
            if (!curr->left) {
                curr->left = pnode;
                ptree->count++;
                return;
            }
            curr = curr->left;
        } else if (val > curr->val) {
            if (!curr->right) {
                curr->right = pnode;
                ptree->count++;
                return;
            }
            curr = curr->right;
        }
    }
}

int binarySearchTree_contains(BinarySearchTree* ptree, int val) {
    if (!ptree->root || !ptree->count) return 0;
    int contains = 0;

    Node* curr = ptree->root;
    while (1) {
        if (curr->val == val) {
            contains = 1;
            return contains;
        }

        if (curr->val < val) {
            if (!curr->right) {
                contains = 0;
                return contains;
            } else {
                curr = curr->right;
            }
        }

        if (curr->val > val) {
            if (!curr->left) {
                contains = 0;
                return contains;
            } else {
                curr = curr->left;
            }
        }
    }

    return contains;
}

// UTILS
static void traverseAndFree(Node* pnode);

static void freeTree(BinarySearchTree* ptree) {
    if (!ptree->root) return;
    traverseAndFree(ptree->root);
}

static void traverseAndFree(Node* pnode) {
    if (pnode->left) traverseAndFree(pnode->left);
    binarySearchTree_node_reset(pnode);
    free(pnode);
    if (pnode->right) traverseAndFree(pnode->right);
}
