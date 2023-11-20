#include <stdio.h>

#define N 3

int out[N];
int used[N];

void printPermuatation();
void permute(int i);

int main()
{
    permute(0);
    return 0;
}

void printPermutation()
{
    int i;
    for(i = 0; i < N; i++)
    {
        printf("%d ", out[i]);
    }
    printf("\n");
}

void permute(int i)
{
    if(i >= N)
    {
        printPermutation();
    }else
    {
        int k;
        for(k = 0; k < N; k++)
        {
            if(!used[k])
            {
                out[i] = k + 1;
                used[k] = 1;
                permute(i + 1);
                used[k] = 0;
            }
        }
    }
}