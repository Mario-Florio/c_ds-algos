#include "../../../test/test.h"
#include "../binarySearchTree.h"

typedef BinarySearchTree_Node Node;

static void binarySearchTree_insertTests();
static void binarySearchTree_containsTests();

static int isValidBinarySearchTree(BinarySearchTree* ptree);

void binarySearchTree_testSuites() {
    printf("====BINARY SEARCH TREE=====\n\n");
    suite("Insert:", binarySearchTree_insertTests);
    suite("Contains:", binarySearchTree_containsTests);
    printf("\n");
}

static void binarySearchTree_insertTests() {
    BinarySearchTree tree;
    BinarySearchTree* ptree = &tree;
    binarySearchTree_init(ptree);

    binarySearchTree_insert(ptree, 4);
    binarySearchTree_insert(ptree, 2);
    binarySearchTree_insert(ptree, 5);
    binarySearchTree_insert(ptree, 1);
    binarySearchTree_insert(ptree, 3);
    binarySearchTree_insert(ptree, 1);
    
    it("Creates a valid binary search tree", isValidBinarySearchTree(ptree));

    int count = tree.count ? tree.count : -1;
    it("Updates count ", count == 5);

    Node* root = tree.root;
    Node* targ = root->left->left;
    it("Increments node count if inserted value is equivalent", targ->count == 2);

    binarySearchTree_reset(ptree);
}

static void binarySearchTree_containsTests() {
    BinarySearchTree tree;
    BinarySearchTree* ptree = &tree;
    binarySearchTree_init(ptree);

    binarySearchTree_insert(ptree, 4);
    binarySearchTree_insert(ptree, 2);
    binarySearchTree_insert(ptree, 5);
    binarySearchTree_insert(ptree, 1);
    binarySearchTree_insert(ptree, 3);
    binarySearchTree_insert(ptree, 1);

    it("Returns truthy if tree contains valiue", binarySearchTree_contains(ptree, 1));
    it("Returns falsy if tree doesn't contains valiue", binarySearchTree_contains(ptree, 7) == 0);

    binarySearchTree_reset(ptree);
}

// UTILS
static void traverseDepthFirstLeftRight(Node* pnode, int vals[], int* pvalsIdx);

static int isValidBinarySearchTree(BinarySearchTree* ptree) {
    int isValidBST = 1;
    int vals[ptree->count];
    int valsIdx = 0;
    traverseDepthFirstLeftRight(ptree->root, vals, &valsIdx);
    for (int i = 0; i < ptree->count-1; i++) {
        if (vals[i] > vals[i+1]) isValidBST = 0;
    }
    return isValidBST;
}

static void traverseDepthFirstLeftRight(Node* pnode, int vals[], int* pvalsIdx) {
    if (pnode->left) traverseDepthFirstLeftRight(pnode->left, vals, pvalsIdx);
    int valsIdx = *pvalsIdx;
    vals[valsIdx] = pnode->val;
    valsIdx++;
    *pvalsIdx = valsIdx;
    if (pnode->right) traverseDepthFirstLeftRight(pnode->right, vals, pvalsIdx);
}
