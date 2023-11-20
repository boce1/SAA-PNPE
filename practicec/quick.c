#include <stdio.h>

void swap(int* arr, int i, int j);
void quickSort(int* arr, int low, int high);
int partition(int* arr, int low, int high);

int main()
{
    int arr[] = {8, 5, 9, 2, 6, 1, 3};   
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
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

int partition(int* arr, int low, int high)
{
    int mid, i, j, pivot;
    mid = (high + low) / 2;
    pivot = arr[mid];

    swap(arr, mid, high);

    i = low - 1;
    for(j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}

void quickSort(int* arr, int low, int high)
{
    if(low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}