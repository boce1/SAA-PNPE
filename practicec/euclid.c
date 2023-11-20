#include <stdio.h>

int euclid(int m, int n);

int main()
{
    printf("%d\n", euclid(564, 1855));
    return 0;
}

int euclid(int m, int n)
{
    if(n <= 0)
    {
        return m;
    }
    if(n > 0)
    {
        if(n > m)
        {
            m = m ^ n;
            n = m ^ n;
            m = m ^ n;
        }

        euclid(n, m % n);
    }
}