#ifndef QUEUE_H 
#define QUEUE_H

#include <stdbool.h>

#define BASE_CAPACITY 10

typedef struct {
    int *data;
    int size;
    int capacity;
} Queue;

/* Operations */ 

Queue* queue_create();

bool queue_isEmpty(Queue *s);
bool queue_enqueue(Queue *s, int num);
int queue_dequeue(Queue *s);
int queue_peek(Queue *s);
int queue_size(Queue *s);

void queue_destroy(Queue *s);

#endif
