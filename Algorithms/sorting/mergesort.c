#include <stdio.h>

void merge(int A[], int n, int l, int r, int m) {
    int B[r];
    for (int i = l; i < m+1; i++) B[i] = A[i];
    for (int i = m+1; i < r+1; i++) B[r+m-i+1] = A[i];
    int i = l;
    int j = r;
    for (int k = l; k < r+1; k++) {
        if (B[i] < B[j]) {
            A[k] = B[i];
            i++;
        } else {
            A[k] = B[j];
            j--;
        }
    }
}

void mergesort(int A[], int n, int l, int r) {
    if (l < r) {
        int m = (int) ((l+r) / 2);
        mergesort(A, n, l, m);
        mergesort(A, n, m+1, r);
        merge(A, n, l, r, m);
    }
    return;
}

void printArr(int A[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return;
}

int main() {
    int A[] = {-41,3,52,-592,2,994,2,3,3,3,3};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Array before sorting: ");
    printArr(A, n);
    mergesort(A, n, 0, n);
    printf("Array after sorting: ");
    printArr(A, n);
    return 0;
}
