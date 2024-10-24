#include "../../../common.h"
#include "methods.h"

typedef LinkedList_Node Node;

static void finish();

void linkedList_access_method(LinkedList* plist) {
    printf("Index? ");
    int idx;
    scanf("%d", &idx);
    fgetc(stdin);

    int val = linkedList_access(plist, idx);

    printf("\033[1;32m"); // green
    printf("\nLinked List %p[%d]: %d\n\n", plist, idx, val);
    printf("\033[1;0m");
    finish();
}

void linkedList_add_method(LinkedList* plist) {
    printf("Index? ");
    int idx;
    scanf("%d", &idx);
    fgetc(stdin);

    printf("Value? ");
    int val;
    scanf("%d", &val);
    fgetc(stdin);

    linkedList_add(plist, idx, val);

    printf("\033[1;32m"); // green
    printf("\nAdded value %d to index %d of Linked List %p.\n\n", val, idx, plist);
    printf("\033[1;0m");
    finish();
}

void linkedList_remove_method(LinkedList* plist) {
    printf("Index? ");
    int idx;
    scanf("%d", &idx);
    fgetc(stdin);

    int val = linkedList_remove(plist, idx);

    printf("\033[1;32m"); // green
    printf("\nRemoved %d from %d of Linked List %p.\n\n", val, idx, plist);
    printf("\033[1;0m");
    finish();
}

void linkedList_push_method(LinkedList* plist) {
    printf("Value? ");
    int val;
    scanf("%d", &val);
    fgetc(stdin);

    linkedList_push(plist, val);

    printf("\033[1;32m"); // green
    printf("\nPushed %d to Linked List %p.\n\n", val, plist);
    printf("\033[1;0m");
    finish();
}

void linkedList_pop_method(LinkedList* plist) {
    int val = linkedList_pop(plist);

    printf("\033[1;32m"); // green
    printf("\nPopped %d from Linked List %p.\n\n", val, plist);
    printf("\033[1;0m");
    finish();
}

void linkedList_shift_method(LinkedList* plist) {
    printf("Value? ");
    int val;
    scanf("%d", &val);
    fgetc(stdin);

    linkedList_shift(plist, val);

    printf("\033[1;32m"); // green
    printf("\nShifted %d to Linked List %p.\n\n", val, plist);
    printf("\033[1;0m");
    finish();
}

void linkedList_unshift_method(LinkedList* plist) {
    int val = linkedList_unshift(plist);

    printf("\033[1;32m"); // green
    printf("\nUnshifted %d from Linked List %p.\n\n", val, plist);
    printf("\033[1;0m");
    finish();
}

void linkedList_print_method(LinkedList* plist) {
    printf("\n");
    printf("\033[1;32m"); // green
    printf("Linked List %p\n", plist);
    printf("Head: %p\n", plist->head);
    printf("Tail: %p\n", plist->tail);
    printf("Count: %d\n", plist->count);
    linkedList_print(plist);
    printf("\033[1;0m");
    printf("\n");
    finish();
}

void linkedList_reset_method(LinkedList* plist) {
    printf("Are you sure? (y/n)");
    char confirm;
    scanf("%c", &confirm);

    if (confirm == 'y') {
        linkedList_reset(plist);

        printf("\033[1;32m"); // green
        printf("\nLinked List %p has been reset.\n\n", plist);
        printf("\033[1;0m");
        scanf("");
        fgetc(stdin);
    } else if (confirm == 'n') {
        printf("\n");
        fgetc(stdin);
        return;
    } else {
        fgetc(stdin);
        linkedList_reset_method(plist);
    }
}

static void finish() {
    printf("Press enter\n");
    scanf("");
    fgetc(stdin);
}
