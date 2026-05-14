#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct node** ls1;
struct node** ls2;

struct node** init() {
    struct node** l;
    l = malloc(sizeof(struct node*));
    *l = NULL;
    return l;
}

int first(struct node** l) {
    if (*l == NULL) return -1;
    else return (*l)->val;
}

void insert(struct node** l, int val) {
    struct node* p;
    struct node* q;

    if (*l == NULL || (*l)->val > val) {
        q = malloc(sizeof(struct node));
        q->val = val;
        q->next = *l;
        *l = q;
    } else {
        p = *l;
        while (p->next != NULL && p->next->val < val) { p = p->next; }
        q = malloc(sizeof(struct node));
        q->val = val;
        q->next = p->next;
        p->next = q;
    }
}