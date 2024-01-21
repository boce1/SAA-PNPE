#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
int hashTable[MAX_N + 1];

int output[MAX_N + 1];
int size = 0;

void uniteArrays(int* A, int m, int* B, int n, int* C, int p);

int main() {
    int A[] = {1,2,5,3,7,8,9, 4};
    int B[] = {2,4,10,7,15,20,9};
    int C[] = {3,2,9,5,4,8};
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);
    int p = sizeof(C) / sizeof(C[0]);

    uniteArrays(A, m, B, n, C, p);

    int i;
    for(i = 0; i < size; i++) {
        printf("%d ", output[i]);
    }

    return 0;
}

void uniteArrays(int* A, int m, int* B, int n, int* C, int p) {
    int i, currentElement;

    for(i = 0; i < m; i++) {
        currentElement = A[i];
        hashTable[currentElement]++;
    }
    for(i = 0; i < n; i++) {
        currentElement = B[i];
        hashTable[currentElement]++;
    }
    for(i = 0; i < p; i++) {
        currentElement = C[i];
        hashTable[currentElement]++;
    }

    for(i = 0; i < MAX_N + 1; i++) {
        if(hashTable[i] >= 3) {
            output[size++] = i;
        }
    }
}