/* 
TASK 2
Given the input array A = (4, 8, 8, 7, 7, 3, 5, 0, 5), show the state of array A when the the outermost loop is completed for the second time.

Answer:
[0, 3, 4, 7, 7, 5, 5, 8, 8]
*/

// C implementation to check result (not part of the exercise)
#include <stdio.h>

void printArr(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) printf(", ");
    }
    printf("]\n");
}

void XSort(int arr[], int n) {  
    int iteration = 0;
    int l = 0;
    int r = n-1;
    int m;

    do {
        for (int j = r; j > l; j--) {
            if (arr[j] < arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;

                m = j;
            }
        }
        l = m;
        for (int j = l; j < r; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                m = j;
            }
        }
        r = m;
        printf("Loop #%d: ", ++iteration);
        printArr(arr, n);
    } while (l < r);
    return;
}

int main() {
    int arr[] = {4, 8, 8, 7, 7, 3, 5, 0, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, n);
    XSort(arr, n);
    return 0;
}
