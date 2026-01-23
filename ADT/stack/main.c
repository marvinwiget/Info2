#include "stack.h"
#include <stdio.h>


int main() {
    Stack *s = stack_create();
    stack_push(s, 4);
    stack_push(s, 5);
    printf("%d\n", stack_pop(s));

    stack_destroy(s);


    return 0;
}
