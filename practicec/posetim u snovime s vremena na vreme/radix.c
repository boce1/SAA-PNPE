#include <stdio.h>

int maxElement(int* arr, int n);
void radixSort(int* arr, int n);

int main() {
    int arr[] = {4, 75, 123, 19, 183, 34};    
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    int i;
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}

int maxElement(int* arr, int n)
{
    int max = arr[0];
    int i;
    
    for(i = 1; i < n; i++)
    {
        if(arr[i] > max) max = arr[i];
    }

    return max;
}

void radixSort(int* arr, int n)
{
    int exp = 1;
    int max = maxElement(arr, n);
    int digitsCount[10];
    int out[n];
    int i;

    while(max / exp > 0)
    {
        for(i = 0; i < 10; i++) digitsCount[i] = 0;
        for(i = 0; i < n; i++)
        {
            digitsCount[arr[i] / exp % 10]++;
        }
        for(i = 1; i < 10; i++) digitsCount[i] += digitsCount[i - 1];
        for(i = n - 1; i >= 0; i--)
        {
            out[--digitsCount[arr[i] / exp % 10]] = arr[i];
        }
        for(i = 0; i < n; i++) arr[i] = out[i];
        exp *= 10;
    }
}