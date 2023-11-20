#include <iostream>

float power(float x, int n);
std::string convertDecimalToBinary(int n);
int sumArr(int* arr, int n);
int sumArr2(int* arr, int n);
bool hasDigit(int n, int d);

int main()
{
    std::cout << power(2, 4) << std::endl;
    std::cout << power(2, -3) << std::endl;
    std::cout << power(5, 0) << std::endl;

    int arr[] = {1,2,3,4,5,6};
    std::cout << sumArr(arr, sizeof(arr) / sizeof(arr[0])) << std::endl;
    std::cout << sumArr2(arr, sizeof(arr) / sizeof(arr[0])) << std::endl;

    std::cout << hasDigit(10, 9) << std::endl;
    std::cout << hasDigit(10, 0) << std::endl;
    std::cout << hasDigit(-123, 1) << std::endl;

    std::cout << convertDecimalToBinary(8) << std::endl;
    std::cout << convertDecimalToBinary(9) << std::endl;
    std::cout << convertDecimalToBinary(10) << std::endl;


    return 0;
}

float power(float x, int n)
{
    if(n == 0)
    {
        return 1;
    }

    if(n > 0)
    {
        return x * power(x, n - 1);
    }else
    {
        return (1 / x) * power(x, n + 1);
    }
}

std::string convertDecimalToBinary(int n)
{
    if(n > 0)
    {
        int digit = n % 2;
        n /= 2;
        return convertDecimalToBinary(n) + std::to_string(digit);
    }
    return "";
}

int sumArr(int* arr, int n)
{
    if(n > 1)
    {
        int* left = arr;
        int sizeLeft = n / 2;
        int* right = arr + sizeLeft;
        int sizeRight = n - sizeLeft;

        return sumArr(left, sizeLeft) + sumArr(right, sizeRight);
    }else
    {
        return arr[0];
    }
}

int sumArr2(int* arr, int n)
{
    int index = n - 1;
    if(index > 0)
    {
        return arr[index] + sumArr2(arr, index);
    }else
    {
        return arr[index];
    }
}

bool hasDigit(int n, int d)
{
    if(n == 0)
    {
        return false;
    }

    int digit = n % 10;
    if(d == digit || d == -digit)
    {
        return true;
    }
    hasDigit(n / 10, d);

}