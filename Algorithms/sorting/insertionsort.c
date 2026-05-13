#include <stdio.h>

void insertionsort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i-1;
        int temp = arr[i];
        while (j >= 0 && temp < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
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

	insertionsort(arr, n);
	printf("after sorting: ");
	printArray(arr, n);
	return 0;
}
