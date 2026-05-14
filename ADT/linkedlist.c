#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct node* new_node(int val) { // create a node and return pointer
    struct node *n = malloc(sizeof(struct node));
    n->val = val;
    n->next = NULL;
    return n;
}

void insertFirst(struct node **root, int val) {
    if (*root == NULL) { // empty list
        *root = new_node(val);
    }
    else {
        struct node *p = *root;
        struct node* new = new_node(val);
        new->next = p;
        *root = new;
    }
}

void insertLast(struct node **root, int val) {
    if (*root == NULL) { // empty list
        *root = new_node(val);
    }
    else {
        struct node *p = *root;
        while (p->next != NULL) { p = p->next; } // go to the end of list and insert
        p->next = new_node(val);
    }
    return;
}

void delete(struct node **root, int target) {
    if (*root == NULL) return; // empty list

    struct node *p = *root;
    if (p->val == target) { // first element is target
        *root = p->next;
        free(p);
    } else {
        while (p->next != NULL && p->next->val != target) { p = p->next; } // check the rest of the list

        if (p->next == NULL) return; // target not found

        struct node *temp = p->next; // rearrange pointers and free target
        p->next = temp->next;
        free(temp);
    }
}

void print(struct node **root) { // print the linked list
    if (*root == NULL) {
        printf("root -|\n");
        return;
    }
    printf("root -> ");
    struct node *p = *root;
    while (p->next != NULL) {
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("%d -|\n", p->val);
    return;
}

struct node** init() { // initilization
    struct node **l = malloc(sizeof(struct node*));
    *l = NULL;
    return l;
}

int main() {
    struct node **root = init();
    print(root);
    insertFirst(root, 3);
    insertFirst(root, 6);
    insertFirst(root, 9);
    insertLast(root, 2);
    insertLast(root, 4);
    insertLast(root, 8);
    print(root);
    
    delete(root, 4);
    delete(root, 9);
    print(root);

    return 0;
}