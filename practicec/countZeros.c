#include <stdio.h>

int count(int* arr, const int n);

int main()
{
    int arr[] = {25, 4, 20, 11, 13, 15};
    printf("%d ", count(arr, 6));
    return 0;
}

int count(int* arr, const int n)
{
    int i, element;
    int countTwos = 0;
    int countFives = 0;

    for(i = 0; i < n; i++)
    {  
        element = arr[i];

        while(element % 2 == 0)
        {
            countTwos++;
            element /= 2;
        }

        while(element % 5 == 0)
        {
            countFives++;
            element /= 5;
        }
    }

    if(countTwos < countFives)
    {
        return countTwos;
    }

    return countFives;
}