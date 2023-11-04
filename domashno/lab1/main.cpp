#include <iostream>
#include <cmath>

void zad1();
void zad3(int &a, int &b);

void zad2();
void zad4(int &a, int &b);
void zad9();
void zad11(int* arr, int n);

int main()
{
    //zad2();

    /*zad 3 and 4*/
    //int n, m;
    //std::cout << "n = ";
    //std::cin >> n;
    //std::cout << "m = ";
    //std::cin >> m;
    //zad3(n, m);
    //zad4(n, m);
    //std::cout << "\nn = " << n << "\nm = " << m << std::endl;
    /*end zad 3 and 4*/

    
    //zad9();

    int test1[] = {1,2,3,-4,-8,7,-8};
    int size1 = sizeof(test1) / sizeof(test1[0]);
    int test2[] = {1,-2,7,-8,9};
    int size2 = sizeof(test2) / sizeof(test2[0]);
    int test3[] = {1, 2,-3,-4,-8,7,-8, 10, 20, -3};
    int size3 = sizeof(test3) / sizeof(test3[0]);
    zad11(test1, size1);
    zad11(test2, size2);
    zad11(test3, size3);

}

void zad1()
{
    float a, b, c, p, s;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << "c = ";
    std::cin >> c;
    p = (a + b + c) / 2;
    s = std::sqrt(p * (p - a) * (p - b) * (p - c));

    std::cout << "Surface area: " << s << std::endl;
}

void zad2()
{
    int n, sum, digit;
    sum = 0;
    std::cout << "n = ";
    std::cin >> n;

    while(n != 0) // for(int i = 0; i < 3; i++)
    {
        digit = n % 10;
        n /= 10;
        sum += digit;
    }

    std::cout << "Sum of digits is " << sum << std::endl;
}

void zad3(int &a, int &b)
{
    a = a * b;
    b = a / b;
    a = a / b;
}


void zad4(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void zad9()
{
    int n = 0;
    int x = 2; 

    while(x < 100)
    {
        x = 2 * x + 10;
        n++;
    }

    std::cout << "X_" << n << " = " << x << std::endl;
}

void zad11(int* arr, int n)
{
    int result = 0;
    for(int i = 0; i < n - 1; i++)
    {
        if((arr[i] * arr[i + 1]) < 0)
        {
            result++;
        }
    }

    std::cout << "There is " << result <<" neightbours pairs with different sign\n";
}