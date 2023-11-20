#include <stdio.h>

void shellSort(int* arr, int n);

int main()
{
    int arr[] = {8, 5, 9, 2, 6, 1, 3};   
    int n = sizeof(arr) / sizeof(arr[0]);
    shellSort(arr, n);
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void shellSort(int* arr, int n)
{
    int step, i, j, temp;
    for(step = n / 2; step > 0; step /= 2)
    {
        for(i = step; i < n; i++)
        {
            for(j = i; j >= step; j -= step)
            {
                if(arr[j] < arr[j - step])
                {
                    temp = arr[j];
                    arr[j] = arr[j - step];
                    arr[j - step] = temp;
                }
            }
        }
    }
}