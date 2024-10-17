#include "testSuites.h"

void queue_accessTests();
void queue_enqueueTests();
void queue_dequeueTests();

void fillQueue(Queue* queue, int amount);

void queue_testSuites() {
    printf("==========QUEUE===========\n\n");
    suite("Access:", queue_accessTests);
    suite("Enqueue:", queue_enqueueTests);
    suite("Dequeue:", queue_dequeueTests);
    printf("\n");
}

void queue_accessTests() {
    Queue queue;
    abstract_linkedList_accessTests(&queue, queue_access);
}

void queue_enqueueTests() {
    Queue queue;
    abstract_linkedList_pushTests(&queue, queue_enqueue);
}

void queue_dequeueTests() {
    Queue queue;
    abstract_linkedList_unshiftTests(&queue, queue_dequeue);
}

// UTILS
void fillQueue(Queue* pqueue, int amount) {
    for (int i = 0; i < amount; i++) {
        queue_enqueue(pqueue, i+1);
    }
}
