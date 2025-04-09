#include <iostream>
#include <vector>
#include <algorithm>

int people;
std::vector<int> cost;
std::vector<int> happy;

int dfs(int index, int health, int pleasure)
{
	if (index == people) return pleasure;
	if (health <= 0) return 0;

	int pass = dfs(index + 1, health, pleasure);

	int pick = 0;
	if (health - cost[index] > 0)
	{
		pick = dfs(index + 1, health - cost[index], pleasure + happy[index]);
	}

	int answer = std::max(pass, pick);
	return answer;
}

int main()
{	
	std::cin >> people;

	for (int i = 0; i < people; ++i)
	{
		int temp;
		std::cin >> temp;
		cost.push_back(temp);
	}

	for (int i = 0; i < people; ++i)
	{
		int temp;
		std::cin >> temp;
		happy.push_back(temp);
	}

	int answer = dfs(0, 100, 0);
	std::cout << answer;
}