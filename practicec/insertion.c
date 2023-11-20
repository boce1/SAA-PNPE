#include <stdio.h>

void insertionSort(int* arr, int n);
void swap(int* arr, int i, int j);

int main()
{
    int arr[] = {8, 5, 9, 2, 6, 1, 3};   
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void swap(int* arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void insertionSort(int* arr, int n)
{
    int i, j;
    for(i = 1; i < n; i++)
    {
        for(j = i; j > 0 && arr[j] < arr[j - 1]; j--)
        {
            swap(arr, j, j - 1);
        }
    }
}