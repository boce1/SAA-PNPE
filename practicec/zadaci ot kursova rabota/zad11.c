#include <stdio.h>

void printSumDigits(int a, int b);
int sumDigits(int n);

int main()
{
    printSumDigits(10, 40);
    return 0;
}

void printSumDigits(int a, int b)
{
    int i, sum;
    for(i = a; i <= b; i++)
    {
        printf("%d ", sumDigits(i));
    }
}

int sumDigits(int n)
{
    if(n == 0) return n;
    return n % 10 + sumDigits(n / 10);
}