#include <stdio.h>

int zad4(int* arr, const int size);
void testZad4(int* arr, const int size, int output);
void zad6(int* arr, const int n);

int main()
{
    // test zad4
    printf("Test zad4\n");
    int arr1[] = {1,5,2,10,4,7}; // (1 < 5 > 2 < 10 > 4 < 7) => true
    testZad4(arr1, sizeof(arr1) / sizeof(arr1[0]), 1);

    int arr2[] = {1,2,4,7,5,8}; // (1 < 2 _<_ 4 < 7 > 5 < 8) => false
    testZad4(arr2, sizeof(arr2) / sizeof(arr2[0]), 0);

    int arr3[] = {2, 6, 3, 5, 1, 10, 7, 9}; // (2 < 6 > 3 < 5 > 1 < 10 > 7 < 9) => true
    testZad4(arr3, sizeof(arr3) / sizeof(arr3[0]), 1);

    int arr4[] = {2, 6, 3, 0, 1, 10, 12, 9}; // (2 < 6 > 3 _>_ 0 _<_ 1 < 10 _<_ 12 _>_ 9) = > false
    testZad4(arr4, sizeof(arr4) / sizeof(arr4[0]), 0);

    int arr5[] = {5, 2, 1, 7, 3}; // (5 _>_ 2 > 1 < 7 > 3) => false
    testZad4(arr5, sizeof(arr5) / sizeof(arr5[0]), 0);
    // ---------------------------- //

    // test zad6
    printf("\nZad6\n");
    int arr6[] = {1, 2, 8, 5, 3, 1, 0};
    zad6(arr6, sizeof(arr6) / sizeof(arr6[0]));

    int arr7[] = {4, 2, 1, 8, 5, 3, 1, 0, 7};
    zad6(arr7, sizeof(arr7) / sizeof(arr7[0]));

    int arr8[] = {1, 2, 3, 4, 5};
    zad6(arr8, sizeof(arr8) / sizeof(arr8[0]));

    int arr9[] = {4, 2, 1, 8, 5, 3, 1, 0, 7, 5};
    zad6(arr9, sizeof(arr9) / sizeof(arr9[0]));

    int arr10[] = {2, 1, 5, 4, 10, 9, 8, 7, 9};
    zad6(arr10, sizeof(arr10) / sizeof(arr10[0]));

    int arr11[] = {3, 2, 5, 4, 10, 0, 3, 2, 1};
    zad6(arr11, sizeof(arr11) / sizeof(arr11[0]));
    /*--------------------------*/

    return 0;
}

/*
4.Да се напише програма, която проверява дали между елементите на редицата 
а0, а1, а2,..., аn са изпълнени релациите: а0 < a1 > a2 < a3...
*/
int zad4(int* arr, const int size)
{
    int i;
    for(i = 0; i < size - 1; i++)
    {
        if(i % 2 == 0 && arr[i] > arr[i + 1])
        {
            return 0;
        }else if(i % 2 == 1 && arr[i] < arr[i + 1])
        {
            return 0;
        }
    }
    return 1;

}

void testZad4(int* arr, const int size, int output)
{
    int outputFunction = zad4(arr, size);
    if(outputFunction == output)
    {
        printf("Test Passed\n");
    }else
    {
        printf("Error\n");
    }
}

/*
6.Даден е едномерен масив с n елемента. Да се напише програма, 
която намира броя на намаляващите редици от елементи в масива, 
тяхната дължина и най-дългата от тях.
*/
void zad6(int* arr, const int n)
{
    int i, len, maxLen, maxIndex, arrIndex;

    len = 1;
    maxLen = 0;
    maxIndex = 0;

    //std::vector<int> lenghts;
    arrIndex = 0;
    int lenghts[n];

    for(i = 1; i < n; i++)
    {
        if(arr[i] < arr[i - 1])
        {
            len++;
        }else
        {
            if(len > maxLen)
            {
                maxLen = len;
                maxIndex = i - maxLen;
            }

            if(len > 1)
            {
                //lenghts.push_back(len);
                lenghts[arrIndex++] = len;
            }

            len = 1;
        }
    }

    if(len > maxLen) // in case subbarray is at the end
    {
        maxLen = len;
        maxIndex = n - maxLen;
    }

    if(len != 1) // in case subbarray is at the end
    {
        //lenghts.push_back(len);
        lenghts[arrIndex++] = len;
    }

    if(maxLen == 1) // there's no subarrays
    {
        maxLen = 0; // not to enter for loop because thres no elements
    }


    // output
    printf("[ ");
    for(i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("]\n");
    printf("Lenght of subarrays: [ ");
    for(i = 0; i < arrIndex; i++)
    {
        printf("%d ", lenghts[i]);
    }
    printf("]   %d subbarrays\n", arrIndex);
    printf("The biggest subbarray : [ ");
    for(i = maxIndex; i < maxIndex + maxLen; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("] --- lenght = %d\n\n", maxLen);
}