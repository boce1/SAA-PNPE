#include <stdio.h>

void heapSort(int* arr, int n);
void heapify(int* arr, int n, int i);

int main()
{
    int arr[] = {8, 5, 9, 2, 6, 1, 3};   
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void heapify(int* arr, int n, int i)
{
    int temp;
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if(right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(i != largest)
    {
        temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapify(arr, n, largest); 
    }
}

void heapSort(int* arr, int n)
{
    int i, temp;
    for(i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for(i = n - 1; i >= 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}