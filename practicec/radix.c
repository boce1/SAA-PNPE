#include <stdio.h>

void radixSort(int* arr, int n);
int maxElement(int* arr, int n);
void makeZeros(int* arr, int n);

int main()
{
    int arr[] = {432, 300, 67, 31, 98, 66, 41, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

int maxElement(int* arr, int n)
{
    int max = arr[0];
    int i;
    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void makeZeros(int* arr, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
}

void radixSort(int* arr, int n)
{
    int i;
    int max = maxElement(arr, n);
    int out[n];
    int digits[10];
    int exp = 1;

    while(max / exp > 0)
    {
        makeZeros(digits, 10);

        for(i = 0; i < n; i++)
        {
            digits[arr[i] / exp % 10]++;
        }

        for(i = 1; i < 10; i++)
        {
            digits[i] += digits[i - 1];
        }

        for(i = n - 1; i >= 0; i--)
        {
            out[--digits[arr[i] / exp % 10]] = arr[i];  
        }

        for(i = 0; i < n; i++)
        {
            arr[i] = out[i];
        }

        exp *= 10;
    }
}