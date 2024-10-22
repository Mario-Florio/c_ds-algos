#include "../../../test/test.h"
#include "../queue.h"
#include "../../linkedList/testSuites/tests/tests.h"

static void queue_accessTests();
static void queue_peekTests();
static void queue_enqueueTests();
static void queue_dequeueTests();

void queue_testSuites() {
    printf("==========QUEUE===========\n\n");
    suite("Access:", queue_accessTests);
    suite("Peek:", queue_peekTests);
    suite("Enqueue:", queue_enqueueTests);
    suite("Dequeue:", queue_dequeueTests);
    printf("\n");
}

static void queue_accessTests() {
    Queue queue;
    abstract_linkedList_accessTests(&queue, queue_access);
}

static void queue_peekTests() {
    Queue queue;
    Queue* pqueue = &queue;
    queue_init(pqueue);

    for (int i = 1; i < 10; i++) queue_enqueue(pqueue, i);

    it("Returns head", queue_peek(pqueue) == 1);
}

static void queue_enqueueTests() {
    Queue queue;
    abstract_linkedList_pushTests(&queue, queue_enqueue);
}

static void queue_dequeueTests() {
    Queue queue;
    abstract_linkedList_unshiftTests(&queue, queue_dequeue);
}
