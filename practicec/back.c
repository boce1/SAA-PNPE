#include <stdio.h>

#define N 3
int arr[N];
int visited[N];

void print();
void permutation(int i);
int isInside(int el);

int main() {
    permutation(0);
    return 0;
}

void print() {
    int i;
    for(int i = 0; i < N; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int isInside(int el) {
    int i;
    for(i = 0; i < N; i++) {
        if(arr[i] == el) {
            return 1;
        }
    }
    return 0;
}

void permutation(int i) {
    int j;
    if(i >= N) {
        print();
    }
    for(j = 0; j < N; j++) {
    
        if(visited[i] == 0) {
            arr[i] = j + 1;
            visited[i] = 1;
            permutation(i + 1);
            visited[i] = 0;
        }
    }
}