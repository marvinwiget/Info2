#include <stdio.h>

void merge(int A[], int n, int l, int r, int m) {
    int B[n];
    for (int i = l; i <= m; i++) B[i] = A[i];
    for (int i = m+1; i <= r; i++) B[r+m-i+1] = A[i];

    int i = l;
    int j = r;
    for (int k = l; k <= r; k++) {
        if (B[i] < B[j]) A[k] = B[i++];
        else A[k] = B[j--];
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

void printArray(int arr[], int n) {
	printf("[");
	for (int i=0; i<n; i++) {
		if (i == n - 1) printf("%d", arr[i]);
		else printf("%d, ", arr[i]);
	}
	printf("]\n");
}

int main() {
	int arr[] = {3,1,5,7,8,3};
	int n = sizeof(arr) / sizeof(int);

	printf("before sorting: ");
	printArray(arr, n);

	mergesort(arr, n, 0, n-1);
	printf("after sorting: ");
	printArray(arr, n);
	return 0;
}