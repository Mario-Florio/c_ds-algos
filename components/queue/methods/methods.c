#include "../../../common.h"
#include "methods.h"

static void finish();

void queue_access_method(Queue* pqueue) {
    printf("Index? ");
    int idx;
    scanf("%d", &idx);
    fgetc(stdin);

    int val = queue_access(pqueue, idx);

    printf("\033[1;32m"); // green
    printf("\nQueue %p[%d]: %d\n\n", pqueue, idx, val);
    printf("\033[1;0m");
    finish();
}

void queue_enqueue_method(Queue* pqueue) {
    printf("Value? ");
    int val;
    scanf("%d", &val);
    fgetc(stdin);

    queue_enqueue(pqueue, val);

    printf("\033[1;32m"); // green
    printf("\nPushed %d to Queue %p.\n\n", val, pqueue);
    printf("\033[1;0m");
    finish();
}

void queue_dequeue_method(Queue* pqueue) {
    int val = queue_dequeue(pqueue);

    printf("\033[1;32m"); // green
    printf("\nUnshifted %d from Queue %p.\n\n", val, pqueue);
    printf("\033[1;0m");
    finish();
}

void queue_peek_method(Queue* pqueue) {
    if (!pqueue->head) {
        printf("\nQueue is empty.\n\n");
        finish();
        return;
    }
    printf("\nFront of queue: %d\n\n", queue_peek(pqueue));
    finish();
}

void queue_print_method(Queue* pqueue) {
    printf("\n");
    printf("\033[1;32m"); // green
    printf("Queue %p\n", pqueue);
    printf("Head: %p\n", pqueue->head);
    printf("Tail: %p\n", pqueue->tail);
    printf("Count: %d\n", pqueue->count);
    linkedList_print(pqueue);
    printf("\033[1;0m");
    printf("\n");
    finish();
}

void queue_reset_method(Queue* pqueue) {
    printf("Are you sure? (y/n)");
    char confirm;
    scanf("%c", &confirm);

    if (confirm == 'y') {
        queue_reset(pqueue);

        printf("\033[1;32m"); // green
        printf("\nQueue %p has been reset.\n\n", pqueue);
        printf("\033[1;0m");
        scanf("");
        fgetc(stdin);
    } else if (confirm == 'n') {
        printf("\n");
        fgetc(stdin);
        return;
    } else {
        fgetc(stdin);
        queue_reset_method(pqueue);
    }
}

// UTILS
static void finish() {
    printf("Press enter\n");
    scanf("");
    fgetc(stdin);
}
