#include <stdio.h>

void coctailShakerSort(int* arr, int n);
void swap(int* arr, int i, int j);

int main()
{
    int arr[] = {8, 5, 9, 2, 6, 1, 3};   
    int n = sizeof(arr) / sizeof(arr[0]);
    coctailShakerSort(arr, n);
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

void coctailShakerSort(int* arr, int n)
{
    int i, left, right, lastSwap;
    left = 0;
    right = n - 1;

    while(left < right)
    {
        for(i = left; i < right; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                swap(arr, i, i + 1);
                lastSwap = i;
            }
        }
        right = lastSwap;

        for(i = right; i > left; i--)
        {
            if(arr[i] < arr[i - 1])
            {
                swap(arr, i, i - 1);
                lastSwap = i;
            }
        }
        left = lastSwap;
    }
}