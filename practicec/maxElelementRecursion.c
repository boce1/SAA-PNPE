#include <stdio.h>

int findMax(int* arr, int low, int high);

int main() {
    int arr[] = {1, 5, -8, 0, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", findMax(arr, 0, size - 1));
    return 0;
}

int findMax(int* arr, int low, int high) {
    int a, b;
    int mid = (low + high) / 2;
    
    if(low == high) {
        return arr[low];
    }
    a = findMax(arr, low, mid);
    b = findMax(arr, mid + 1, high);

    if(a > b) {
        return a;
    }else {
        return b;
    }
}