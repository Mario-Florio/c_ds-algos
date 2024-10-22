#include "queue.h"

void queue_init(Queue* pqueue) {
    linkedList_init(pqueue);
}

void queue_reset(Queue* pqueue) {
    linkedList_reset(pqueue);
}

int queue_access(Queue* pqueue, int idx) {
    return linkedList_access(pqueue, idx);
}

int queue_peek(Queue* pqueue) {
    return pqueue->head->val;
}

void queue_enqueue(Queue* pqueue, int val) {
    linkedList_push(pqueue, val);
}

int queue_dequeue(Queue* pqueue) {
    return linkedList_unshift(pqueue);
}
