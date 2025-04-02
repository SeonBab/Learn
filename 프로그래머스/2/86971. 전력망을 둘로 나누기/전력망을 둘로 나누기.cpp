#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

int dfs(int node)
{
    visited[node] = true;
    int count = 1;
    
    for (int next : graph[node])
    {
        if (visited[next] == false)
        {
            count += dfs(next);
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;

    graph.assign(n + 1, vector<int>());
    for (auto& wire : wires)
    {
        int a = wire[0], b = wire[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (auto &wire : wires)
    {
        int a = wire[0], b = wire[1];
        
        graph[a].erase(remove(graph[a].begin(), graph[a].end(), b), graph[a].end());
        graph[b].erase(remove(graph[b].begin(), graph[b].end(), a), graph[b].end());
        
        visited.assign(n + 1, false);
        int subTreeSize = dfs(a);
        int otherTreeSize = n - subTreeSize;
        
        answer = min(answer, abs(subTreeSize - otherTreeSize));
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    return answer;
}