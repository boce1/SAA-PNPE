#include <iostream>
#include <vector>

#define M 3

void zad12(int* arr, int n);
void zad13(int* arr, int n);
void zad15(int arr[M][M]);
void zad16();
void zad19();

void zad14(int arr[][M], int row);

int main()
{
    //int arr[] = {1,2,3};
    //zad12(arr, sizeof(arr) / sizeof(arr[0]));

    /*  */
    //int arr2[] = {1,1,1};
    //int arr3[] = {1,1,1, 2,2,3,4,4,4};
    //int arr4[] = {1,2,1,4,4,4};
    //int arr5[] = {1,2,2,1};
    //int arr6[] = {1,5,5,10,10};
    //
    //zad13(arr2, sizeof(arr2) / sizeof(arr2[0]));
    //zad13(arr3, sizeof(arr3) / sizeof(arr3[0]));
    //zad13(arr4, sizeof(arr4) / sizeof(arr4[0]));
    //zad13(arr5, sizeof(arr5) / sizeof(arr5[0]));
    //zad13(arr6, sizeof(arr6) / sizeof(arr6[0]));
    /*  */

    int arr[][M] = {
        {1,2,1},
        {4,5,6},
        {1,8,1}
    };
    //zad14(arr, sizeof(arr) / sizeof(arr[0]));
    
    //zad15(arr);

    //zad16();

    zad19();

    return 0;
}

void zad12(int* arr, int n)
{
    int i, j;
    int product = 1;
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if((arr[i] + arr[j]) <= 120)
            {
                product *= (arr[i] + arr[j]);
            }
        }
    }

    std::cout << "Product of all pairs elements is " << product << std::endl;
}

void zad13(int* arr, int n)
{
    int result = 0;
    
    int el = arr[0];
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == el)
        {
            count++;
        }
        else
        {
            if(count > 1)
            {   
                result++;
            }
            el = arr[i];
            count = 1;
        }
    }

    if(count > 1)
    {
        result++;
    }

    std::cout << "Result is " << result << std::endl;
}

void zad14(int arr[][M], int row)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < M; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void zad15(int arr[M][M])
{
    int sum = 0;
    int i;

    for(i = 0; i < M; i++)
    {
        sum += arr[0][i] + arr[M - 1][i];
    }

    for(i = 1; i < M - 1; i++)
    {
        sum += arr[i][0] + arr[i][M - 1];
    }

    std::cout << "Sum is " << sum << std::endl;
}

void zad16()
{
    int n;
    std::cout << "n = ";
    std::cin >> n;

    int i, j;
    int arr[n][n];
    std::vector<int> out;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            std::cout << "arr[" << i << "]" << "[" << j << "] = ";
            std::cin >> arr[i][j];
            out.push_back(arr[i][j]);
        }
    }

    // sum main diagonal
    int sum = 0;
    for(i = 0; i < n; i++)
    {
        sum += arr[i][i];
    }
    out.push_back(sum);

    // sums of elements of the rows
    sum = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            sum += arr[i][j];
        }
        out.push_back(sum);
        sum = 0;
    }

    // count elements bellow main deagonal x: x < i + j
    int count = 0;
    for(i = 1; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(arr[i][j] < (i + j))
            {
                count++;
            }
        }
    }
    out.push_back(count);

    std::cout << "[ ";
    for(i = 0; i < out.size(); i++)
    {
        std::cout << out[i] << " ";
    }
    std::cout << "]";
}

void zad19()
{
    int i, j, n;
    std::cout << "n = ";
    std::cin >> n;

    int arr[n][n];
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            std::cout << "arr[" << i << "]" << "[" << j << "] = ";
            std::cin >> arr[i][j];
        }
    }

    int sum = 0;
    for(i = 0; i < n; i++)
    {
        sum += arr[i][n - i - 1];
    }

    std::cout << "Sum of seconds diagonal is " << sum << std::endl;
}
