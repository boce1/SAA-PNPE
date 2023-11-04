#include <iostream>
#include <vector>

bool zad4(int* arr, int n);
void zad6(int* arr, int n);
void testZad(bool zadOutput, bool expectedOutput);

int main()
{
    /*-----------zad4-----------*/
    // x0 < x1 > x2 < x3 > x4 < x5
    std::cout << "Exercise 4\n";
    int arr1[] = {1,5,2,10,4,7}; // (1 < 5 > 2 < 10 > 4 < 7) => 1
    testZad(zad4(arr1, sizeof(arr1) / sizeof(arr1[0])), 1);

    int arr2[] = {1,2,4,7,5,8}; // (1 < 2 _<_ 4 < 7 > 5 < 8) => 0
    testZad(zad4(arr2, sizeof(arr2) / sizeof(arr2[0])), 0);

    int arr3[] = {2, 6, 3, 5, 1, 10, 7, 9}; // (2 < 6 > 3 < 5 > 1 < 10 > 7 < 9) => 1
    testZad(zad4(arr3, sizeof(arr3) / sizeof(arr3[0])), 1);

    int arr4[] = {2, 6, 3, 0, 1, 10, 12, 9}; // (2 < 6 > 3 _>_ 0 _<_ 1 < 10 _<_ 12 _>_ 9) = > 0
    testZad(zad4(arr4, sizeof(arr4) / sizeof(arr4[0])), 0);

    int arr5[] = {5, 2, 1, 7, 3}; // (5 _>_ 2 > 1 < 7 > 3) => 0
    testZad(zad4(arr5, sizeof(arr5) / sizeof(arr5[0])), 0);
    /*--------------------------*/
    
    std::cout << "\n\n";

    /*-----------zad6-----------*/
    std::cout << "Exercise 6\n";
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

bool zad4(int* arr, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        if(i % 2 == 0 && arr[i] > arr[i + 1])
        {
            return 0;
        }else if(i % 2 != 0 && arr[i] < arr[i + 1])
        {
            return 0;
        }
    }

    return 1;
}

void testZad(bool zadOutput, bool expectedOutput)
{
    if(zadOutput == expectedOutput)
    {
        std::cout << "Test passed\n";
    }else
    {
        std::cout << "Error, expected ";
        if(expectedOutput)
        {
            std::cout << "1\n";
        }else
        {
            std::cout << "0\n";
        }
    }
}

void zad6(int* arr, int n)
{
    int i, len, maxLen, maxIndex;

    len = 1;
    maxLen = 0;
    maxIndex = 0;

    std::vector<int> lenghts; 

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
                lenghts.push_back(len);
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
        lenghts.push_back(len);
    }

    if(maxLen == 1) // there's no subarrays
    {
        maxLen = 0; // not to enter for loop because thres no elements
    }
    // output
    std::cout << "--------------------\narr = [ ";
    for(i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;


    std::cout << "subarr = [ ";
    for(i = maxIndex; i < maxIndex + maxLen; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "]\tlenght = " << maxLen << std::endl;


    std::cout << "n of subarr = " << lenghts.size() << std::endl << "lenghts = [ ";
    for(i = 0; i < lenghts.size(); i++)
    {
        std::cout << lenghts[i] << " ";
    }
    std::cout << "]\n--------------------\n\n";
    // output

}