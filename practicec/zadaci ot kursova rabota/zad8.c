#include <stdio.h>

void printInverseArrRecursion(int* arr, int n);

int main()
{
    int arr1[] = {5, 1, 0, 3, 0, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printInverseArrRecursion(arr1, n1);
    return 0;
}

void printInverseArrRecursion(int* arr, int n)
{
    if(n > 0)
    {
        int index = n - 1;
        printf("%d ", arr[index]);
        printInverseArrRecursion(arr, index);
    }
    
}