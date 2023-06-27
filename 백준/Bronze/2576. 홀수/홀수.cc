#include <iostream>

int main()
{
    int sum{}, min{ 100 }, num{}, count{ 7 };

    for (int i = 0; i < count; ++i)
    {
        std::cin >> num;

        if (num % 2 == 1)
        {
            sum += num;

            if (min > num)
            {
                min = num;
            }
        }
    }

    if (min == 100 && sum == 0)
    {
        std::cout << -1 << std::endl;
    }
    else
    {
        std::cout << sum << std::endl;
        std::cout << min << std::endl;
    }
}