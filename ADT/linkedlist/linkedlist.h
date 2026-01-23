#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>


typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

/* Operations */ 

LinkedList* ll_create();
bool ll_isEmpty(LinkedList *l);
bool ll_add(LinkedList *l, int val);
bool ll_removeLast(LinkedList *l);
bool ll_removeAt(LinkedList *l, int index);
int ll_size(LinkedList *l);
void ll_print(LinkedList *l);

void ll_destroy(LinkedList *l);

#endif
