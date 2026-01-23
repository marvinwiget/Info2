#include "queue.h"
#include <stdio.h>


int main() {
    Queue *q = queue_create();
    queue_enqueue(q, 2);
    queue_enqueue(q, 4);
    queue_enqueue(q, 6);
    printf("%d\n", queue_peek(q));
    printf("%d\n", queue_dequeue(q));
    printf("%d\n", queue_peek(q));
    printf("%d\n", queue_dequeue(q));
    printf("%d\n", queue_peek(q));
    printf("%d\n", queue_dequeue(q));
    printf("%d\n", queue_peek(q));
    printf("%d\n", queue_dequeue(q));

    queue_destroy(q);
    return 0;
}
