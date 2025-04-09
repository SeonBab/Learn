#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
	std::string str;
	std::cin >> str;

	std::unordered_map<char, int> alphabetMap;

	for (char i = 'a'; i <= 'z'; ++i)
	{
		alphabetMap[i] = 0;
	}

	for (const char alphabet : str)
	{
		++alphabetMap[alphabet];
	}

	for (char i = 'a'; i <= 'z'; ++i)
	{
		std::cout << alphabetMap[i] << " ";
	}
}