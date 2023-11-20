#include <stdio.h>

void mergeSort(int* arr, int n);

int main()
{
    int arr[] = {8, 5, 9, 2, 6, 1, 3};   
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, n);
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void mergeSort(int* arr, int n)
{
    if(n > 1)
    {
        int leftLen = n / 2;
        int rightLen = n - leftLen;

        int leftArr[leftLen];
        int rightArr[rightLen];

        int i, j, k;
        for(i = 0; i < leftLen; i++)
        {
            leftArr[i] = arr[i];
        }
        for(i = 0; i < rightLen; i++)
        {
            rightArr[i] = arr[i + leftLen];
        }

        mergeSort(leftArr, leftLen);
        mergeSort(rightArr, rightLen);

        i = j = k = 0;
        while(i < leftLen && j < rightLen)
        {
            if(leftArr[i] < rightArr[j])
            {
                arr[k++] = leftArr[i++];
            }else
            {
                arr[k++] = rightArr[j++];
            }
        }

        while(i < leftLen)
        {
            arr[k++] = leftArr[i++];
        }
        while(j < rightLen)
        {
            arr[k++] = rightArr[j++];
        }
    }

}