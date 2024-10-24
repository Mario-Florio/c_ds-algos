#ifndef datastructures_queue_queue_h
#define datastructures_queue_queue_h

#include "../linkedList/linkedList.h"

typedef LinkedList Queue;

void queue_init(Queue* pqueue);
void queue_reset(Queue* pqueue);
int queue_access(Queue* pqueue, int idx);
int queue_peek(Queue* pqueue);
void queue_enqueue(Queue* pqueue, int val);
int queue_dequeue(Queue* pqueue);

#endif