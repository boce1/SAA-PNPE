#include <stdio.h>

void moveZerosToTheEnd(int* arr, int n);
void swap(int* arr, int i, int j);
void print(int* arr, int n);

int main()
{
    int arr1[] = {5, 1, 0, 3, 0, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    moveZerosToTheEnd(arr1, n1);
    print(arr1, n1);
    //printf("%d ", n1);
    return 0;
}

void print(int* arr, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void moveZerosToTheEnd(int* arr, int n)
{
    int i, j;
    for(i = 0, j = 0; i < n; i++)
    {
        if(arr[j] != 0)
        {
            j++;
        }else if(arr[i] != 0)
        {
            swap(arr, i, j);
            j++;
        }
    }
}