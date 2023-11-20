#include <stdio.h>

void countSort(int* arr, int n);
int maxElement(int* arr, int n);

int main()
{
    int arr[] = {4, 3, 6, 3, 9, 6, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    countSort(arr, n);
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

void countSort(int* arr, int n)
{
    int out[n];
    int max = maxElement(arr, n);
    int arrCount[max + 1];

    int i;
    for(i = 0; i <= max; i++)
    {
        arrCount[i] = 0;
    }

    for(i = 0; i < n; i++)
    {
        arrCount[arr[i]]++;
    }

    for(i = 1; i <= max; i++)
    {
        arrCount[i] += arrCount[i - 1];
    }

    for(i = 0; i < n; i++)
    {
        out[--arrCount[arr[i]]] = arr[i]; 
    }

    for(i = 0; i < n; i++)
    {
        arr[i] = out[i];
    }
}