#include <iostream>
#include <algorithm>

#define totalDwarfCount 9
#define targetDwarfCount 7

int main()
{
	int totalDwarf[totalDwarfCount];
	int totalStature = 0;
	for (int i = 0; i < totalDwarfCount; ++i)
	{
		std::cin >> totalDwarf[i];
		totalStature += totalDwarf[i];
	}

	std::sort(&totalDwarf[0], &totalDwarf[totalDwarfCount]);

	int frontIndex = 0;
	int BackIndex = totalDwarfCount - 1;

	totalStature -= totalDwarf[frontIndex];
	totalStature -= totalDwarf[BackIndex];

	while (true)
	{
		if (totalStature > 100)
		{
			totalStature += totalDwarf[frontIndex];
			
			++frontIndex;
			if (frontIndex == BackIndex)
			{
				++frontIndex;
			}

			totalStature -= totalDwarf[frontIndex];
		}
		else if (totalStature < 100)
		{
			totalStature += totalDwarf[BackIndex];

			--BackIndex;
			if (frontIndex == BackIndex)
			{
				--BackIndex;
			}

			totalStature -= totalDwarf[BackIndex];
		}
		else
		{
			break;
		}
	}

	for (int i = 0; i < totalDwarfCount; ++i)
	{
		if (i == frontIndex || i == BackIndex)
		{
			continue;
		}

		std::cout << totalDwarf[i] << std::endl;
	}

	return 0;
}
