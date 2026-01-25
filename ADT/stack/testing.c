#include <stdio.h>
#include "stack.h"

int main(void) {
    Stack *s = stack_create();
    
    for (int i=0; i<200; i++) {
        stack_push(s, i);
    }
    stack_peek(s);
    for(int i=0; i<200; i++) {
        printf("%d has been removed\n", stack_pop(s));
    }
    return 0;
}
