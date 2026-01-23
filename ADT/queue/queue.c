#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "queue.h"

Queue* queue_create() {
    Queue *q = malloc(sizeof(Queue));
    if (q == NULL) {
        printf("queue alloc failed (QUEUE_CREATE)");
        return NULL;
    }
    q->size = -1;
    q->capacity = BASE_CAPACITY;
    q->data = malloc(q->capacity * sizeof(int));
    if (q->data == NULL) {
        printf("queue data alloc failed (QUEUE_CREATE)");
        return NULL;
    }
    return q;
}

bool queue_isEmpty(Queue *q) {
    return (q->size < 0) ? true : false;
}

bool queue_enqueue(Queue *q, int num) {
    assert(q != NULL);

    if (q->size == q->capacity) {
        q->capacity *= 2;
        int *temp = realloc(q->data, q->capacity * sizeof(int));
        if (temp == NULL) {
            printf("queue realloc failed (QUEUE_ENQUEUE)");
            return false;
        }
        q->data = temp;
    }
    q->data[++q->size] = num;
    return true;
}

int queue_dequeue(Queue *q) {
    assert(q != NULL);
    assert(!queue_isEmpty(q));

    if (q->size < q->capacity / 2 && q->capacity / 2 >= BASE_CAPACITY) {
        q->capacity /= 2;
        int *temp = realloc(q->data, q->capacity * sizeof(int));
        if (temp == NULL) {
            printf("queue realloc failed (QUEUE_DEQUEUE)");
            return -1;
        }
        q->data = temp;
    }
    int res = q->data[0];
    q->data = &(q->data[1]);
    q->size--;
    return res;
}

int queue_peek(Queue *q) {
    assert(q != NULL);
    assert(!queue_isEmpty(q));
    
    return q->data[0];
}

int queue_size(Queue *q) {
    assert(q != NULL);
    
    return q->size + 1;
}

void queue_destroy(Queue *q) {
    if (q != NULL) {
        if (q->data != NULL) {
            free(q->data);
        }
        free(q);
    }
    return;
}









