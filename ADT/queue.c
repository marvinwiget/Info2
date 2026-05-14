#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

struct queue {
    int a[QUEUE_SIZE];
    int h; // head, first element of queue
    int t; // tail, last element
};

struct queue* create() {
    struct queue* q= malloc(sizeof(struct queue));
    q->h = 0;
    q->t = 0;
    return q;
}

void enqueue(struct queue **queue, int val) {
    struct queue *q = *queue;
    q->a[q->t] = val;
    q->t = (q->t + 1) % QUEUE_SIZE;
}

int dequeue(struct queue **queue) {
    struct queue *q = *queue;
    int i = q->h;
    q->h = (q->h + 1) % QUEUE_SIZE;
    return q->a[i];
}

void print(struct queue **queue) {
    struct queue *q = *queue;

	int i = q->h;
    while (i != q->t) {
        printf("%d ", q->a[i]);
        i = (i + 1) % QUEUE_SIZE;
    }
    printf("\n");
}


int main() {
    struct queue **queue = malloc(sizeof(struct queue*));
    *queue = create();

    enqueue(queue, 2);
    enqueue(queue, 4);
    enqueue(queue, 6);
    enqueue(queue, 8);
    print(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    print(queue);

    enqueue(queue, 1);
    enqueue(queue, 3);
    print(queue);

    dequeue(queue);
    print(queue);
    return 0;
}