#include "../../common.h"
#include "../../__utils__/arrContains/arrContains.h"
#include "../../__utils__/trimString/trimString.h"
#include "../../dataStructures/queue/queue.h"
#include "args.h"
#include "methods/methods.h"

static void getInput(Queue* pqueue);

void queue_suite() {
    Queue queue;
    Queue* pqueue = &queue;
    queue_init(pqueue);

    printf("Queue %p initialized.\n\n", pqueue);
    getInput(pqueue);

    queue_reset(pqueue);
}

static void getInput(Queue* pqueue) {
    printf("What would you like to do?\n");
    printf("    1. Access\n");
    printf("    2. Enqueue\n");
    printf("    3. Dequeue\n");
    printf("    4. Peek\n");
    printf("    5. Print\n");
    printf("    6. Reset\n");
    printf("    7. Return to Menu\n");
    printf("\n");

    char line[256];

    if (fgets(line, sizeof line, stdin) != NULL) {
        trimString(line);

        int accessArgsSize = sizeof(ACCESS_ARGS) / sizeof(ACCESS_ARGS[0]);
        int enqueue = sizeof(ENQUEUE_ARGS) / sizeof(ENQUEUE_ARGS[0]);
        int dequeueArgsSize = sizeof(DEQUEUE_ARGS) / sizeof(DEQUEUE_ARGS[0]);
        int peekArgsSize = sizeof(PEEK_ARGS) / sizeof(PEEK_ARGS[0]);
        int printArgsSize = sizeof(PRINT_ARGS) / sizeof(PRINT_ARGS[0]);
        int resetArgsSize = sizeof(RESET_ARGS) / sizeof(RESET_ARGS[0]);
        int returnArgsSize = sizeof(RETURN_ARGS) / sizeof(RETURN_ARGS[0]);

        if (arrContains(accessArgsSize, ACCESS_ARGS, line)) {
            queue_access_method(pqueue);
        } else if (arrContains(enqueue, ENQUEUE_ARGS, line)) {
            queue_enqueue_method(pqueue);
        } else if (arrContains(dequeueArgsSize, DEQUEUE_ARGS, line)) {
            queue_dequeue_method(pqueue);
        } else if (arrContains(peekArgsSize, PEEK_ARGS, line)) {
            queue_peek_method(pqueue);
        } else if (arrContains(printArgsSize, PRINT_ARGS, line)) {
            queue_print_method(pqueue);
        } else if (arrContains(resetArgsSize, RESET_ARGS, line)) {
            queue_reset_method(pqueue);
        } else if (arrContains(returnArgsSize, RETURN_ARGS, line)) {
            return;
        } else {
            printf("\nPlease choose a valid option\n\n");
        }

        getInput(pqueue);
    }
}
