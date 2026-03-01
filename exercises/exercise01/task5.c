/*

gcc pairSum_skeleton.c -o pairSum_skeleton; ./pairSum_skeleton Seed rand? ArrayLength ElementSum

gcc pairSum_skeleton.c -o pairSum_skeleton; ./pairSum_skeleton 1 1 9 8
gcc pairSum_skeleton.c -o pairSum_skeleton; ./pairSum_skeleton 23 1 9 8
gcc pairSum_skeleton.c -o pairSum_skeleton; ./pairSum_skeleton 1 1 10 8
gcc pairSum_skeleton.c -o pairSum_skeleton; ./pairSum_skeleton 2 1 500000 55
gcc pairSum_skeleton.c -o pairSum_skeleton; ./pairSum_skeleton 2 0 500000 55
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define m 1000000

int A[m];
int i, j, n, c;

//-----------------------------------------------------

void printA() {
  if (n < 10) {
    printf("A = ");
    for (i = 0; i < n-1; i++) { printf("%d,", A[i]); }
    printf("%d\n", A[n-1]);
  } else {
    printf("(n=%d)\n", n);
  }
}

//-----------------------------------------------------
// O(n^2) time complexity
bool pairSum() {
  // put your code here
    for (i = 0; i < n - 1; i++) {
        for (j = i+1; j < n; j++) {
            if (A[i] + A[j] == c) return true;
        }
    }
    return false;
}

//-----------------------------------------------------
// O(n) time complexity
bool pairSumSorted() {
  // put your code here
  int l = 0;
  int r = n-1;

  while (l < r) {
      if (A[l] + A[r] > c) r--;
      else if (A[l] + A[r] < c) l++;
      else if (A[l] + A[r] == c) return true;
  }
  return false;
}

//-----------------------------------------------------

int main(int argc, char **argv) {
  int s, r;
  sscanf(argv[1],"%d", &s);
  sscanf(argv[2],"%d", &r);
  sscanf(argv[3],"%d", &n);
  sscanf(argv[4],"%d", &c);

  // when try to measure worst case runtime, set c larger than maximum possible sum
  // If you want to measure the worst case runtime, uncomment the following line
  // c = 30 * n;
  
  srand(s);
  if (r) { A[0] = rand() % (10 * n); } else { A[0] = rand() % 10; }
  for (i = 1; i < n; i++) {
    if (r) {
        A[i] = rand() % (10 * n);
    } else {
      A[i] = A[i-1] + rand() % 10;
    }
  } 
  printf("the array was filled with random integers\n");
  printA();

  // measure pairSum runtime
  clock_t start_pairSum = clock();
  int result_pairSum = pairSum();
  clock_t end_pairSum = clock();
  double time_pairSum = (double)(end_pairSum - start_pairSum) / CLOCKS_PER_SEC;

  // measure pairSumSorted runtime
  clock_t start_pairSumSorted = clock();
  int result_pairSumSorted = pairSumSorted();
  clock_t end_pairSumSorted = clock();
  double time_pairSumSorted = (double)(end_pairSumSorted - start_pairSumSorted) / CLOCKS_PER_SEC;

  if ((r && result_pairSum) || (!r && result_pairSumSorted)) {
      printf("%d and %d add up to %d\n", A[i], A[j], c);
  } else {
      printf("no pair adds up to %d (i=%d,j=%d)\n", c, i, j);
  }

  printf("pairSum() execution time: %f seconds\n", time_pairSum);
  printf("pairSumSorted() execution time: %f seconds\n", time_pairSumSorted);
  
}
