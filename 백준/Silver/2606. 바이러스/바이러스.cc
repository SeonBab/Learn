#include <iostream>
#include <vector>

int answer = 0;

void dfs(const std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int index)
{
	visited[index] = true;

	for (int next : graph[index])
	{
		if (!visited[next])
		{
			++answer;
			dfs(graph, visited, next);
		}
	}
}

int main()
{
	int computerCount, pairCount;
	std::cin >> computerCount >> pairCount;

	std::vector<std::vector<int>> graph(computerCount + 1);

	for (int i = 0; i < pairCount; ++i)
	{
		int computerA, computerB;

		std::cin >> computerA >> computerB;

		graph[computerA].push_back(computerB);
		graph[computerB].push_back(computerA);
	}

	std::vector<bool> visited(computerCount + 1);

	dfs(graph, visited, 1);

	std::cout << answer << std::endl;
}