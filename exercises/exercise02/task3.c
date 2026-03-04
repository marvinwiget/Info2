/*
  hanoi_skeleton.c

  Compile & run examples (same interface as the reference solution):
    gcc hanoi_skeleton.c -o hanoi_skeleton -lm; ./hanoi_skeleton 3 5     # show after 5 moves
    gcc hanoi_skeleton.c -o hanoi_skeleton -lm; ./hanoi_skeleton 8 213   # show after 213 moves
    gcc hanoi_skeleton.c -o hanoi_skeleton -lm; ./hanoi_skeleton 6 0     # show initial state
    gcc hanoi_skeleton.c -o hanoi_skeleton -lm; ./hanoi_skeleton 4 -1    # show after each move

  Arguments:
    argv[1] = N  (number of disks, up to 9)
    argv[2] = K  (which move number to display; -1 means display every move)
*/

#include <stdio.h>
#include <math.h>


// -----------------------------------------------------------------------------
// Global state (already provided)
//
// p[0] = peg A, p[1] = peg B, p[2] = peg C
// -----------------------------------------------------------------------------

int p[3];     // the three pegs encoded as integers
int N;        // number of disks

int M;        // counter for number of moves
int K;        // number of state to be displayed (-1 = all states)


// -----------------------------------------------------------------------------
// Printing helpers (already implemented)
// -----------------------------------------------------------------------------

void print_disk(int d, char c) {
  int k;
  for (k = 0; k < N-d+1; k++) { printf(" "); }
  for (k = 0; k < 2*d-1; k++) { printf("%c", c); }
  for (k = 0; k < N-d+1; k++) { printf(" "); }
}

void print_pegs() {
  int i, j, l;
  int t[3] = { p[0], p[1], p[2] };
  if (M != K && K != -1) { return; }
  printf("Tower of Hanoi pegs after %d moves:\n", M);
  j = pow(10, N-1);
  for (l = 0; l < N; l++) {
    for (i = 0; i < 3; i++) {
      if (t[i] / j != 0) {
        print_disk(t[i]%10, '*');
        t[i] = t[i] / 10;
      } else {
        print_disk(1, ' ');
      }
    }
    j = j / 10;
    printf("\n");    
  }
}


// -----------------------------------------------------------------------------
// Hanoi algorithm (you implement this)
//
// Conceptual meaning of Hanoi(n, A, B, C):
// Move n disks from peg A to peg B using peg C as auxiliary.
// -----------------------------------------------------------------------------

void Hanoi(int n, int A, int B, int C) {
  // Implement the recursive Hanoi function here


}


// -----------------------------------------------------------------------------
// Main program
// -----------------------------------------------------------------------------

int main(int argc, char **argv) {
  // Basic argument parsing (assumes correct input format for the exercise)
  sscanf(argv[1], "%d", &N);
  sscanf(argv[2], "%d", &K);

  // Initialize pegs:
  // Put disks 1..N on peg A (p[0]) with 1 on top (last digit).
  // Example for N=4: p[0] becomes 4321, p[1]=0, p[2]=0
  int m = 1;
  p[0] = 0;
  p[1] = 0;
  p[2] = 0;

  for (int i = 0; i < N; i++) {
    p[0] = p[0] + (i + 1) * m;
    m = m * 10;
  }

  M = 0;
  print_pegs();          // show initial state
  Hanoi(N, 0, 1, 2);     // move all disks from A to B using C

  return 0;
}
