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
    Queue* pqueue = &queue;
    queue_init(pqueue);
    fillQueue(pqueue, 9);

    int val = queue_access(pqueue, 4);

    it("Accesses accurate index", val == 5);

    int headVal = queue.head ? queue.head->val : 0;
    it("Returns head if idx is less than zero", headVal == 1);

    int tailVal = queue.tail ? queue.tail->val : 0;
    it("Returns tail if idx is greater than count", tailVal == 9);

    queue_reset(pqueue);
}

void queue_enqueueTests() {
    Queue queue;
    Queue* pqueue = &queue;
    queue_init(pqueue);

    queue_enqueue(pqueue, 1);
    queue_enqueue(pqueue, 2);
    queue_enqueue(pqueue, 3);
    queue_enqueue(pqueue, 4);
    queue_enqueue(pqueue, 5);
    queue_enqueue(pqueue, 6);
    queue_enqueue(pqueue, 7);
    queue_enqueue(pqueue, 8);
    queue_enqueue(pqueue, 9);

    int tailVal = queue.tail ? queue.tail->val : 0;
    it("Adds to end of queue", tailVal == 9);
    it("Updates count", queue.count == 9);

    queue_reset(pqueue);
}

void queue_dequeueTests() {
    Queue queue;
    Queue* pqueue = &queue;
    queue_init(pqueue);
    fillQueue(pqueue, 9);

    int val = queue_dequeue(pqueue);
    it("Removes first node", val == 1);
    int headVal = queue.head ? queue.head->val : -1;
    it("Updates head", headVal == 2);
    it("Updates count", queue.count == 8);

    queue_reset(pqueue);
}

// UTILS
void fillQueue(Queue* pqueue, int amount) {
    for (int i = 0; i < amount; i++) {
        queue_enqueue(pqueue, i+1);
    }
}
