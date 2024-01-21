#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
int arr[MAX_N];
int n = 0;

int addElement();

int main() {

    return 0;
}

int addElement() {
    int i;
    int element;
    int negativeCount = 0;
    for(i = 0; i < n; i++) {
        if(arr[i] < 0) negativeCount++;
        if(negativeCount >= 3 && i % 2 == 0) {
            printf("x = ");
            fflush(stdin);
            scanf("%d", &element);
            arr[n++] = element;
        }
    }
}