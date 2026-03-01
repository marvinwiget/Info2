#include <stdio.h>

void printMatrix(int n, int mat[n][n]) {
    printf("[\n");
    for (int i = 0; i < n; i++) {
        printf("  [");
        for (int j = 0; j < n; j++) {
            printf("%d", mat[i][j]);
            if (j != n-1) printf(", ");
        }
        printf("]");
        if (i != n-1) printf("\n");
    }
    printf("\n]\n");
}

void multiplyMatrix(int n, int result[n][n], int mat1[n][n], int mat2[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    } 
}

int main(int argc, char** argv) {
    int num1, num2, num3, num4;
    printf("input 4 integers: ");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    int matrix[2][2] = 
        {
            {num1, num2},
            {num3, num4}
        }; 
    int n = sizeof(matrix) / sizeof(matrix[0]);
    int result[n][n];
    
    multiplyMatrix(n, result, matrix, matrix);

    printf("Matrix before squaring: \n");
    printMatrix(n, matrix);
    printf("Matrix after squaring: \n");
    printMatrix(n, result);

    return 0;
}
