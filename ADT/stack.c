#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5

struct Stack {
    int a[STACK_SIZE];
    int t;
};

struct Stack* create() {
    struct Stack *s = malloc(sizeof(struct Stack));
    s->t = 0;
    return s;
}

void push(struct Stack** s, int val) {
    struct Stack *stack = *s;
    if (stack->t >= STACK_SIZE) return; // stack overflow
    stack->a[stack->t++] = val;
    return;
}

int pop(struct Stack **s) {
    struct Stack *stack = *s;
    if (stack->t <= 0) return -1; // stack already empty
    --stack->t;
    return stack->a[stack->t];
}

void drop(struct Stack **s) {
    free(*s);
}

void print(struct Stack **s) {
    struct Stack *stack = *s;
    int n = stack->t;

	printf("[");
	for (int i=0; i<n; i++) {
		if (i == n - 1) printf("%d", stack->a[i]);
		else printf("%d, ", stack->a[i]);
	}
	printf("]\n");
}

int main() {
    struct Stack **s = malloc(sizeof(struct Stack*));
    *s = create();

    push(s, 2);
    push(s, 4);
    push(s,6);
    push(s, 8);
    print(s);

    pop(s);
    pop(s);
    print(s);

    push(s, 1);
    push(s, 3);
    print(s);

    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    print(s);

    drop(s);

    return 0;
}