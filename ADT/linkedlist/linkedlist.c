#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


LinkedList* ll_create() {
    LinkedList *l = malloc(sizeof(LinkedList));
    if (l == NULL) {
        printf("linkedlist mem alloc failed (LL_CREATE)");
        return NULL;
    }
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
    return l;
}

bool ll_isEmpty(LinkedList *l) {
    return (l->size > 0) ? false : true;
}

bool ll_add(LinkedList *l, int val) {
    assert(l != NULL);

	Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        printf("node mem alloc failed (LL_ADD)");
        return false;
    }
	node->val = val;
	node->next = NULL;

	if (ll_isEmpty(l)) {
		l->head = node;
		l->tail = node;
	} else {
		l->tail->next = node;
		l->tail = node;
	}
	l->size++;
    return true;
}

bool ll_removeLast(LinkedList *l) {
    assert(l != NULL);
    assert(!ll_isEmpty(l));

	Node *curr = l->head;
	while (curr->next != l->tail) {
		curr = curr->next;
	}
	free(curr->next);
	curr->next = NULL;
    l->tail = curr;
	l->size--;
	
    return true;
}

bool ll_removeAt(LinkedList *l, int index) {
    assert(l != NULL);
    assert(!ll_isEmpty(l));
    assert(l->size >= index);
   
    Node *curr = l->head;
	Node *before;
	Node *target;
	for (int i=0; i<index+1; i++) {
		if (i == index-1) {
			before = curr;
		}
		if (i == index) {
			target = curr;
		}
		curr = curr->next;
	}
	free(target);
	before->next = curr;
	l->size--;
    
    return true;
}

int ll_size(LinkedList *l) {
    return l->size;
}

void ll_print(LinkedList *l) {
    assert(l != NULL); 

	Node *curr = l->head;
	printf("(");
	while (curr != NULL) {
		printf("%d", curr->val);
		curr = curr->next;
		if (curr != NULL) {
			printf(" -> ");
		}
	}
	printf(")\n");
}

void ll_destroy(LinkedList *l) {
    if (l == NULL) return;
    if (ll_isEmpty(l)) {
        free(l);
        return;
    }

    Node *curr = l->head;
    Node *next;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    free(l);
    return;
}
