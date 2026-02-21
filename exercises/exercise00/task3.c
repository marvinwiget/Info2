/* PSEUDOCODE */
/*

Input: An array A[1..n] with n distinct integers, where n ≥ 2.
Output: the second largest integer in A

function findSecondLargest(array[1..n])
    n = array.length

    if array[1] > array[2]
        largest = array[1]
        secondLargest = array[2]
    else 
        largest = array[2]
        secondLargest = array[1]
    
    for i: 3..n
        if array[i] > largest
            secondLargest = largest
            largest = array[i]
        
        else if array[i] > secondLargest
            secondLargest = array[i]

    return secondLargest

*/

// C IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


int findSecondLargest(int array[], int n) {
    int largest, secondLargest;

    // set standard values 
    if (array[0] > array[1]) {
        largest = array[0];
        secondLargest = array[1];
    } else {
        largest = array[1];
        secondLargest = array[0];
    }
    
    // loop through array to check if there are bigger values
    for (int i = 2; i < n; i++) {
        if (array[i] > largest) {
            secondLargest = largest;
            largest = array[i];
        } 
        else if (array[i] > secondLargest) {
            secondLargest = array[i];
        }
    }
    return secondLargest;
}

void printArray(int array[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
        if (i != n-1) printf(", ");
    }
    printf("]\n");
}

int main() {
    // set random seed
    srand(time(NULL));

    // determine random array length between 2 - 10
    int n = 2 + (rand() % 8);

    // create and fill array with random distinct values
    int array[n];
    int num;
    bool numValid;
    for (int i = 0; i < n; i++) {
        
        numValid = false;
        while (!numValid) {
            num = rand() % 21; // max value capped to 20
            numValid = true;
            for (int j = 0; j < i; j++) {
                if (array[j] == num) numValid = false;
            }
        }
        array[i] = num;
    }

    // call function and save result in a variable
    int result = findSecondLargest(array, n);

    // print the array and the result
    printArray(array, n);
    printf("second largest integer: %d\n", result);
    
    return 0;
}
