#include <iostream>
#include <vector>
#include <utility>
#include <string>

#define N 3

std::vector<std::pair<int, int>> matrixPairs(int arr[N][N]);
void printPairs(std::vector<std::pair<int, int>> arr);
int factorial(int n);
std::string convertDecimalToBinary(int num);
float power(float x, int n);
int sumArrayRecursion1(int* arr, int n);
int sumArrayRecursion2(int* arr, int n);
bool hasDigit(int num, int d);
int reverseDigit(int n);
bool isMonotoniues(int* arr, int n);
void reverse(int n);

int main()
{
    int arr[N][N] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    std::vector<std::pair<int, int>> test = matrixPairs(arr);
    printPairs(test);
    std::cout << factorial(5) << std::endl;
    std::cout << factorial(4) << std::endl;

    std::string n1 = convertDecimalToBinary(8);
    std::string n2 = convertDecimalToBinary(2);
    std::string n3 = convertDecimalToBinary(10);
    std::string n4 = convertDecimalToBinary(15);
    std::cout << n1 << std::endl;
    std::cout << n2 << std::endl;
    std::cout << n3 << std::endl;
    std::cout << n4 << std::endl;

    float a1 = power(2, 3);
    float a2 = power(2, -3);
    float a3 = power(2, 4);
    float a4 = power(16, -2);
    std::cout << a1 << std::endl;
    std::cout << a2 << std::endl;
    std::cout << a3 << std::endl;
    std::cout << a4 << "\n\n";

    int arrSum[] = {1, 2, 3, 4, 5, 1, 2};
    std::cout << sumArrayRecursion1(arrSum, sizeof(arrSum) / sizeof(arrSum[0])) << std::endl;
    std::cout << sumArrayRecursion2(arrSum, sizeof(arrSum) / sizeof(arrSum[0])) << "\n\n";
    //sumArrayRecursion1(arrSum, sizeof(arrSum) / sizeof(arrSum[0]));

    std::cout << hasDigit(10, 2) << std::endl;
    std::cout << hasDigit(2, 5) << std::endl;
    std::cout << hasDigit(15, 5) << std::endl;
    std::cout << hasDigit(-123, 1) << std::endl << std::endl;
    
    std::cout << isMonotoniues(arrSum, sizeof(arrSum) / sizeof(arrSum[0])) << std::endl;
    int arrSum2[] = {1, 2, 3, 4, 5, 6, 7};
    std::cout << isMonotoniues(arrSum2, sizeof(arrSum2) / sizeof(arrSum2[0])) << std::endl;

    return 0;
}

std::vector<std::pair<int, int>> matrixPairs(int arr[N][N])
{
    std::vector<std::pair<int, int>> out;
    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j < i; j++)
        {
            out.push_back(std::pair<int, int>(arr[i][j], arr[j][i]));
        }
    }

    return out;
}

void printPairs(std::vector<std::pair<int, int>> arr)
{
    std::cout << "{ ";
    for(int i = 0; i < arr.size(); i++)
    {   
        std::cout << "[" << arr[i].first << ", " << arr[i].second << "] ";
    }
    std::cout << "}\n"; 
}

int factorial(int n)
{
    if(n <= 1)
    {
        return n;
    }
    return n * factorial(n - 1);
}

std::string convertDecimalToBinary(int num)
{
    if(num > 0)
    {
        int digit = num % 2;
        num /= 2;
        return convertDecimalToBinary(num) + std::to_string(digit);
    }
    return "";
}

float power(float x, int n)
{
    if(n == 0)
    {
        return 1;
    }else if(n > 0)
    {
        return x * power(x, n - 1);
    }else
    {
        return (1/x) * power(x, n + 1);
    }
}

int sumArrayRecursion1(int* arr, int n)
{
    int index = n - 1;
    if(index <= 0)
    {
        return arr[index];
    }
    return arr[index] + sumArrayRecursion1(arr, index);
}

int sumArrayRecursion2(int* arr, int n)
{
    if(n > 1)
    {
        int* left = arr;
        int sizeLeft = n / 2;
        int* right = arr + sizeLeft;
        int sizeRight = n - sizeLeft;

        return sumArrayRecursion2(left, sizeLeft) + sumArrayRecursion2(right, sizeRight);
    }else
    {
        return arr[0];
    }
}

bool hasDigit(int num, int d)
{
    if(num == 0)
    {
        return 0;
    }

    int currentDigit = num % 10;
    if(currentDigit == d || currentDigit == -d)
    {
        return 1;
    }
    num /= 10;
    hasDigit(num, d);
}

bool isMonotoniues(int* arr, int n)
{
    int index = n - 1;
    if(index <= 0)
    {
        return 1;
    }
    if(arr[index] < arr[index - 1])
    {
        return 0;
    }
    isMonotoniues(arr, index);
}

void reverse(int n)
{
    if(n > 0)
    {
        std::cout << n % 10;
        reverse(n/10);
    }
}