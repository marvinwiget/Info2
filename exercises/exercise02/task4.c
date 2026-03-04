/*
  triangle_sum_skeleton.c

  Compile & run:
    gcc triangle_sum_skeleton.c -o triangle_sum_skeleton; ./triangle_sum_skeleton
*/

#include <stdio.h>


// -----------------------------------------------------------------------------
// Printing helper (already implemented)
// -----------------------------------------------------------------------------

void print_level(const int A[], int n, int level) {
    for (int j = 0; j <= level; j++) {
        printf(" ");
    }

    for (int j = 0; j < n; j++) {
        if (A[j] < 10) {
            printf("%d  ", A[j]);
        } else {
            printf("%d ", A[j]);
        }
    }
    printf("\n");
}


// -----------------------------------------------------------------------------
// Pyramid/triangle algorithm (you implement this)
// -----------------------------------------------------------------------------

void draw_pyramid(const int A[], int n, int level) {
    // Here implement the recursive function
    if (n == 0) return;
    int new[n-1];
    for (int i = 0; i < n-1; i++) {
        new[i] = A[i] + A[i+1];
    }
    draw_pyramid(new, n-1, level+1);
    print_level(A, n, level);
}


// -----------------------------------------------------------------------------
// Main (already implemented)
// -----------------------------------------------------------------------------

int main(void) {
    int A[] = {5, 4, 6, 1, 3};
    int n = (int)(sizeof(A) / sizeof(A[0]));

    draw_pyramid(A, n, 1);

    return 0;
}
