#include <stdio.h>

void selectionsort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min]) min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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

	selectionsort(arr, n);
	printf("after sorting: ");
	printArray(arr, n);
	return 0;
}
