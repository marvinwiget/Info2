#include <stdio.h>


int diagonalSum(int arr[4][4]) {
    int n = 4;
    int m = 4;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) sum += arr[i][j];
        }
    }
    return sum;
}

void printArr(int arr[4][4]) {
    int n = 4;
    int m = 4;
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("[");
        for (int j = 0; j < m; j++) {
            printf("%d", arr[i][j]);
            if (j != m - 1) printf(", ");
        }
        printf("]");
        if (i != n - 1) printf("\n");
    }
    printf("]\n");
}

int main() {
    int arr[4][4] = {
        {2, 4, 1, 3},
        {5, 7, 8, 2},
        {9, 6, 4, 1},
        {3, 8, 5, 6}
    };

    int result = diagonalSum(arr);

    printArr(arr);
    printf("diagonal sum: %d\n", result);

    return 0;
}
