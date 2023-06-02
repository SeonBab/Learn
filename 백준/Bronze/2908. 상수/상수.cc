#include <iostream>

int main()
{
    int a{}, b{}, num1{}, num2{};

    std::cin >> a >> b;

    for (int i = 0; i < 3; ++i)
    {
        num1 = a % 10 + (num1 * 10);
        num2 = b % 10 + (num2 * 10);

        a /= 10;
        b /= 10;
    }

    if (num1 > num2)
    {
        std::cout << num1;
    }
    else
    {
        std::cout << num2;
    }
}