#include <stdio.h>

// return index of target if found, else -1
int binarysearchITER(int arr[], int n, int target) {
    int m;
    int l = 0;
    int r = n-1;
    while (l <= r) {
        m = (int) ((l+r) / 2);
        if (arr[m] == target) return m;
        else if (arr[m] < target) l = m+1;
        else r = m-1;
    }
    return -1;
}

int binarysearchREC(int arr[], int n, int target, int l, int r) {
    // Base case
    if (l > r) return -1;

    // Recursive case
    int m = (int) ((l+r)/2);
    if (arr[m] == target) return m;
    else if (arr[m] < target) return binarysearchREC(arr, n, target, m+1, r);
    else return binarysearchREC(arr, n, target, l, m-1);
}

int main() {
    int arr[] = {1,2,3,5,6,7,9,10}; // array MUST be sorted
    int n = sizeof(arr) / sizeof(int);

    int target = 3;

    int result1 = binarysearchITER(arr, n, target);
    int result2 = binarysearchREC(arr, n, target, 0, n-1);


    printf("result iterative: %d\nresult recursive: %d\n", result1, result2);
    return 0;
}