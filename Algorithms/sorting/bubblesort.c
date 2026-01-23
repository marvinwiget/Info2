#include <stdio.h>

/*
 * BUBBLE SORT ALGORITHM
 * COMPARISONS: O(N^2) 
 * WORST-CASE SWAPS: O(N^2)
 * BEST-CASE SWAPS: 0
*/

void bubbleSort(int arr[], int n);
void swap(int *a, int *b);
void printArray(int arr[], int n);

int main() {
	// create arrays
	int arr1[] = {3,1,5,7,8,3};
	int arr2[] = {99,66,77,67,33,44,11,33,44,766};
	int n1 = sizeof(arr1) / sizeof(int);
	int n2 = sizeof(arr2) / sizeof(int);

	// first array
	printf("First array before Bubble Sort: ");
	printArray(arr1, n1);

	printf("First array after Bubble Sort: "); 
	bubbleSort(arr1, n1);
	printArray(arr1, n1);

	printf("\n\n");

	// second array
	printf("Second array before Bubble Sort: ");
	printArray(arr2, n2);

	printf("Second array after Bubble Sort: "); 
	bubbleSort(arr2, n2);
	printArray(arr2, n2);
	return 0;
}

void bubbleSort(int arr[], int n) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (arr[i] < arr[j]) swap(&arr[i], &arr[j]);
		}
	}
	return;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
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
