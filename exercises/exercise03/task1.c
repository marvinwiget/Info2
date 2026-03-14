#include <stdio.h>
#include <stdlib.h>
#include <time.h> // measuring run time

int n, t;
int A[10000000000];

int linear_search(int A[], int n, int t) {
    for(int i = 0; i < n; i++) {
        if (A[i] == t) {
            return 1; // found in the array
        }
    }
    return 0; // not found
}

int binary_search(int A[], int n, int t) {
    // TASK 1.A) IMPLEMENT BINARY SEARCH
    int l = 0;
    int r = n-1;
    int m;
    while (l < r) {
        m = (int) ((l+r) / 2);
        if (A[m] == t) return 1;
        else if (A[m] > t) l = m+1;
        else r = m-1;
    }
    return 0;
}

//----- Helper method for task 1.c) no changes required but possible -----
void compare_binary_and_linear()
{
    int first_n = 100000;
    int n_step_multiplier = 10;
    int n_arrays = 4;
    // Note: Also change x in line with "int A[x];" such that
    // x >= first_n + n_arrays*n_step_multiplier
    int t = 0;
    n = first_n;
    int count = 100;
    double run_time;
    clock_t start, end;
    srand(time(NULL));

    for(int i = 0; i < n_arrays; i++)
    {
        printf("Testing array with %d elements:", n);
        start = clock();
        for(int c = 1; c <= count; c++) {
            t = rand() % n;
            linear_search(A, n, t); // complete your implementation
        }
        end = clock();
        run_time = ((double)(end - start))/(CLOCKS_PER_SEC/1000);
        printf("Linear search takes : %f milliseconds\n", run_time / count);

        start = clock();
        for(int c = 1; c <= count; c++) {
            t = rand() % n;
            binary_search(A, n, t); // complete your implementation
        }
        end = clock();
        run_time = ((double)(end - start))/(CLOCKS_PER_SEC/1000);
        printf("Binary search takes : %f milliseconds\n", run_time / count);

        n = n * n_step_multiplier;
        printf("\n");
    }
    printf("Note: The time measured here is not the execution time experienced while waiting. The clock() function in C returns the approximate processor time that is consumed by the program which is the number of clock ticks used by the program since the program started. The time is converted to seconds using the CLOCKS_PER_SEC constant.");

}

int main() {
    int B[] = {4,7,10,9,2,5,6,1,3,8};
    int sorted_B[] = {1,2,3,4,5,6,7,8,9,10};
    int n_B = sizeof(B) / sizeof(B[0]);
    int target = 6;

    int res_linear_search = linear_search(B, n_B, target);
    int res_binary_search = binary_search(sorted_B, n_B, target);

    printf("Linear search returned: %d\n",res_linear_search);
    printf("Binary search returned: %d\n",res_binary_search);

    // OPTIONAL TASK 1.C) COMPARE THE RUNTIMES
    compare_binary_and_linear();
}
