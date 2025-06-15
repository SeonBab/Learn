#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> dp;
vector<bool> visited;

void dfs(int node)
{
    visited[node] = true;
    dp[node][0] = 0;
    dp[node][1] = 1;
    
    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor);
            
            dp[node][0] += dp[neighbor][1];
            dp[node][1] += min(dp[neighbor][0], dp[neighbor][1]);
        }
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    
    graph.assign(n + 1, vector<int>());
    dp.assign(n + 1, vector<int>(2, 0));
    visited.assign(n + 1, false);
    
    for (const auto& edge : lighthouse)
    {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    dfs(1);
    
    answer = min(dp[1][0], dp[1][1]);
    
    return answer;
}