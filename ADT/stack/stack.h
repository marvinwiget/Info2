#ifndef STACK_H 
#define STACK_H

#include <stdbool.h>

#define BASE_CAPACITY 10

typedef struct {
    int *data;
    int size;
    int capacity;
} Stack;

/* Operations */ 

Stack* stack_create();

bool stack_isEmpty(Stack *s);
bool stack_push(Stack *s, int num);
int stack_pop(Stack *s);
int stack_peek(Stack *s);
int stack_size(Stack *s);

void stack_destroy(Stack *s);

#endif
