#include <stdio.h>

void printArray(int array[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
        if (i != n-1) printf(", ");
    }
    printf("]\n");
}

void bubblesort(int array[], int n) {
   printArray(array, n);

   for (int i = n; i > 1; i--) {
       for (int j = 1; j < i; j++) {
           if (array[j] < array[j-1]) {
               int temp = array[j];
               array[j] = array[j-1];
               array[j-1] = temp;
           }
       }
       printArray(array, n);
   }
}

int main(void) {
    int array[] = {15, 5, 1, 4, 2, 8, 7};

    int n = sizeof(array) / sizeof(array[0]);

    bubblesort(array, n);
    return 0;
}
