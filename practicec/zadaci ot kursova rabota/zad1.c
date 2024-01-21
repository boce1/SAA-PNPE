#include <stdio.h>

#define N 3

int magicSquare(int arr[N][N]);

int main()
{
    int arr[N][N] = {
        {1,1,1}, 
        {1,1,1}, 
        {1,1,1}
    };

    printf("%d ", magicSquare(arr));
    return 0;
}

int magicSquare(int arr[N][N])
{
    int vals[N + 2];
    int index = 0;

    int i, j, sum;
    sum = 0;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            sum += arr[i][j];
        }
        vals[index++] = sum;
        sum = 0;
    }

    for(i = 0; i < N; i++)
    {
        sum += arr[i][i];
    }
    vals[index++] = sum;
    sum = 0;

    for(i = N - 1; i >= 0; i--)
    {
        sum += arr[i][i];
    }
    vals[index] = sum;

    for(i = 1; i <= index; i++)
    {
        if(vals[i] != vals[i - 1])
        {
            return 0;
        }
    }

    return 1;
}