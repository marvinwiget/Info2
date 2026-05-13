#include <stdio.h>

int parent(int i) { return (int) (i/2); }
int left(int i) { return (int) (2*i + 1); }
int right(int i) { return (int) (2*i + 2); }

void heapify(int arr[], int n, int i) {
    int m = i;
    int l = left(i);
    int r = right(i);
    
    if (l < n && arr[m] < arr[l]) m = l;
    if (r < n && arr[m] < arr[r]) m = r;

    if (i != m) {
        int temp = arr[i];
        arr[i] = arr[m];
        arr[m] = temp;

        heapify(arr, n, m);
    }
}

void buildheap(int arr[], int n) {
    int m = (int) (n/2);
    for (int i = m; i >= 0; i--) heapify(arr, n, i);
}

void heapsort(int arr[], int n) {
    int s = n;
    buildheap(arr, n);
    for (int i = n-1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        s--;
        heapify(arr, s, 0);
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

	heapsort(arr, n);
	printf("after sorting: ");
	printArray(arr, n);
	return 0;
}