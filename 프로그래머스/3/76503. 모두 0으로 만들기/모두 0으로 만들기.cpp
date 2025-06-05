#include <vector>
#include <cmath>

using namespace std;

long long answer = 0;
vector<vector<int>> graph;
vector<bool> visited;
vector<long long> weights;

long long dfs(int nodeIndex)
{
    visited[nodeIndex] = true;
    
    for (int next : graph[nodeIndex])
    {
        if(!visited[next])
        {
            long long childWeight = dfs(next);
            
            weights[nodeIndex] += childWeight;
            answer += abs(childWeight);
        }
    }
    
    return weights[nodeIndex];
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    
    long long totalSum = 0;
    
    int n = a.size();
    
    for (int e : a)
    {
        totalSum += e;
    }
    
    if (totalSum != 0)
    {
        return -1;
    }
    
    graph.resize(n);
    visited.resize(n, false);
    weights.assign(a.begin(), a.end());
    
    for (auto& edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    dfs(0);
    
    return answer;
}