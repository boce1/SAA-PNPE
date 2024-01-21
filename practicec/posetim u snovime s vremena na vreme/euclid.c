#include <stdio.h>

int eu1(int n, int m);
int eu2(int n, int m);

int main()
{
    printf("%d \n", eu2(50, 110));
    return 0;
}

int eu1(int n, int m)
{
    if(m == 0) return n;
    eu1(m, n % m);
}

int eu2(int n, int m)
{
    if(n == m) return n;
    if(n > m) eu2(n - m, m);
    else eu2(n, m - n);
}