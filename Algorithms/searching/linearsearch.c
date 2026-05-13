#include <stdio.h>

// return index of target if found, else -1
int linearsearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int main() {
    int arr[] = {4, 2, 7, 6, 1, 3, 9};
    int n = sizeof(arr) / sizeof(int);

    int target = 7;

    int result = linearsearch(arr, n, target);

    printf("result: %d\n", result);
    return 0;
}