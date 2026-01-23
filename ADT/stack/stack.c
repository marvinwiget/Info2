#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "stack.h"

Stack* stack_create() {
    Stack *s = malloc(sizeof(Stack));
    if (s == NULL) {
        printf("stack alloc failed (STACK_CREATE)");
        return NULL;
    }
    s->size = -1;
    s->capacity = BASE_CAPACITY;
    s->data = malloc(s->capacity * sizeof(int));
    if (s->data == NULL) {
        printf("stack data alloc failed (STACK_CREATE)");
        return NULL;
    }
    return s;
}

bool stack_isEmpty(Stack *s) {
    return (s->size < 0) ? true : false;
}

bool stack_push(Stack *s, int num) {
    assert(s != NULL);

    if (s->size == s->capacity) {
        s->capacity *= 2;
        int *temp = realloc(s->data, s->capacity * sizeof(int));
        if (temp == NULL) {
            printf("stack realloc failed (STACK_PUSH)");
            return false;
        }
        s->data = temp;
    }
    s->data[++s->size] = num;
    return true;
}

int stack_pop(Stack *s) {
    assert(s != NULL);
    assert(!stack_isEmpty(s));

    if (s->size < s->capacity / 2 && s->capacity / 2 >= BASE_CAPACITY) {
        s->capacity /= 2;
        int *temp = realloc(s->data, s->capacity * sizeof(int));
        if (temp == NULL) {
            printf("stack realloc failed (STACK_POP)");
            return -1;
        }
        s->data = temp;
    }
    return s->data[s->size--];
}

int stack_peek(Stack *s) {
    assert(s != NULL);
    assert(!stack_isEmpty(s));
    
    return s->data[s->size];
}

int stack_size(Stack *s) {
    assert(s != NULL);
    
    return s->size + 1;
}

void stack_destroy(Stack *s) {
    if (s != NULL) {
        if (s->data != NULL) {
            free(s->data);
        }
        free(s);
    }
    return;
}









