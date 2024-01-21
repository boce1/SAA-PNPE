#include <stdio.h>

int sumDigits(int n);

int main()
{
    int a;
    printf("a = ");
    scanf("%d", &a);
    printf("%d\n", sumDigits(a));
    return 0;
}

int sumDigits(int n)
{
    if(n == 0) return n;
    return n % 10 + sumDigits(n / 10);
}