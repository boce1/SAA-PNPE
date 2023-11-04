#include <iostream>
#include <vector>
// daden e dvumeren masiv, da se definira i inicializija ednomeren masiv
// ss slednite elementi
// 1st element borja na necetnite el na glavnija diagonal
// 2nd sumata na el po vtoricnija diagonal
// 3rd sumata na elementite po perimetara na dvumernija masiv
// 4th maksimalnata po stojnost suma el po stlbovete na dvumernija masiv
// i ostanlaite sumite na elelemnite po redovete

#define M 3

std::vector<int> zad(int arr[M][M]);

int main()
{
    int arr_test[M][M] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    std::vector<int> output = zad(arr_test);
    std::cout << "[ ";
    for(int i = 0; i < output.size(); i++)
    {
        std::cout << output[i] << " ";
    }
    std::cout << "]" << std::endl;
    return 0;
}

std::vector<int> zad(int arr[M][M])
{    
    std::vector<int> out;

    // 1
    int numOdd = 0;
    int i;
    for(i = 0; i < M; i++)
    {
        if(arr[i][i] % 2 == 1)
        {
            numOdd++;
        }
    }
    out.push_back(numOdd);
    //

    // 2
    int sumSecondDiagonal = 0;
    for(i = 0; i < M; i++)
    {
        sumSecondDiagonal += arr[M - i - 1][M - i - 1];
    }
    out.push_back(sumSecondDiagonal);
    //

    // 3
    int sumPerimeter = 0;
    for(i = 0; i < M; i++)
    {
        sumPerimeter += arr[0][i] + arr[M - 1][i];
    }
    for(i = 1; i < M - 1; i++)
    {
        sumPerimeter += arr[i][0] + arr[i][M - 1];
    }
    out.push_back(sumPerimeter);
    // 

    // 4
    int j;
    int columnSum = 0;
    int maxSum = 0;
    for(i = 0; i < M; i++)
    {
        for(j = 0; j < M; j++)
        {
            columnSum += arr[j][i];
        }
        if(columnSum > maxSum)
        {   
            maxSum = columnSum;
        }
        columnSum = 0;
    }   
    out.push_back(maxSum);

    int sumRow = 0;
    for(i = 0; i < M; i++)
    {
        for(j = 0; j < M; j++)
        {
            sumRow += arr[i][j];
        }
        out.push_back(sumRow);
        sumRow = 0;
    }

    //for(i = 0; i < M; i++)
    //{
    //    for(j = 0; j < M; j++)
    //    {
    //        std::cout << arr[i][j] << " ";
    //    }
    //    std::cout << std::endl;
    //}
//
    //std::cout << "[ ";
    //for(i = 0; i < out.size(); i++)
    //{
    //    std::cout << out[i] << " ";
    //}
    //std::cout << "]" << std::endl;
    return out;

}