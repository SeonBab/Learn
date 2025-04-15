#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
	int t;
	std::cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int n;
		std::cin >> n;

		std::vector<std::string> numStr;

		for (int j = 0; j < n; ++j)
		{
			std::string str;
			std::cin >> str;

			numStr.push_back(str);
		}

		std::sort(numStr.begin(), numStr.end());

		bool isValid = true;

		for (int i = 0; i < numStr.size() - 1; ++i)
		{
			std::string current = numStr[i];
			std::string next = numStr[i + 1];

			if (next.compare(0, current.size(), current) == 0)
			{
				isValid = false;
				break;
			}
		}

		if (isValid)
		{
			std::cout << "YES" << std::endl;
		}
		else
		{
			std::cout << "NO" << std::endl;
		}
	}
}