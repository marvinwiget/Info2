#include "linkedlist.h"

#include <stdio.h>

int main() {
    printf("---------------\n");
    LinkedList *l = ll_create();
    ll_add(l, 2);
    ll_add(l, 4);
    ll_add(l, 6);
    printf("add 2, 4, 6 to the linkedlist\n");
    ll_print(l);

    ll_removeLast(l);
    printf("remove the last element of the list\n");
    ll_print(l);

    ll_add(l,6);
    ll_add(l, 8);
    printf("add 6 and 8 to the list\n");
    ll_print(l);

    ll_removeAt(l, 1);
    printf("remove element at index 1\n");
    ll_print(l);

    ll_add(l, 10);
    ll_add(l, 12);
    printf("add 10 and 12 to the list\n");
    ll_print(l);

    ll_removeAt(l, 4);
    printf("remove the element at index 4\n");
    ll_print(l);

    ll_destroy(l);
    return 0;
}
