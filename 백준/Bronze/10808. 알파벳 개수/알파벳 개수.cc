#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string input;
    std::cin >> input;

    std::vector<int> count(26, 0);

    for (char alphabet : input)
    {
        count[alphabet - 'a']++;
    }

    for (int i = 0; i < 26; ++i)
    {
        std::cout << count[i] << " ";
    }
}