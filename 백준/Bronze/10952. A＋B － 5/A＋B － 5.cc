#include <iostream>

int main()
{
    int a{}, b{}, c{};
    
    while (std::cin >> a >> b)
    {
        c = a + b;
    
        if (c > 0)
        {
            std::cout << c << std::endl;
        }
    }

}