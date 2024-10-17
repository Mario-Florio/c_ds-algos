#ifndef c_dsalgos_queue_queue_h
#define c_dsalgos_queue_queue_h

#include "../linkedList/linkedList.h"

typedef LinkedList Queue;

void queue_init(Queue* pqueue);
void queue_reset(Queue* pqueue);
int queue_access(Queue* pqueue, int idx);
void queue_enqueue(Queue* pqueue, int val);
int queue_dequeue(Queue* pqueue);

#endif