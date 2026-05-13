#include <stdio.h>

int hoarepartition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l-1;
    int j = r+1;

    while (1) {
        do { j--; } while (arr[j] > pivot);
        do { i++; } while (arr[i] < pivot);

        if (i >= j) return j;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void quicksort(int arr[], int l, int r) {
    if (l < r) {
        int m = hoarepartition(arr, l, r);
        quicksort(arr, l, m);
        quicksort(arr, m+1, r);
    }
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

	quicksort(arr, 0, n-1);
	printf("after sorting: ");
	printArray(arr, n);
	return 0;
}