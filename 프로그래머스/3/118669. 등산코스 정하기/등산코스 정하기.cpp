#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer(2);
    
    vector<vector<pair<int, int>>> graph(n + 1);
    for (const auto& path : paths)
    {
        int u = path[0], v = path[1], w = path[2];
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    
    unordered_set<int> summitSet(summits.begin(), summits.end());
    
    vector<int> intensity(n + 1, INT_MAX);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    for (int gate : gates)
    {
        intensity[gate] = 0;
        pq.emplace(0, gate);
    }
    
    while (!pq.empty())
    {
        auto [CurrentIntensity, node] = pq.top();
        pq.pop();
        
        if (CurrentIntensity > intensity[node])
        {
            continue;
        }
        
        if (summitSet.count(node))
        {
            continue;
        }
        
        for (const auto& [next, weight] : graph[node])
        {
            int newIntensity = max(CurrentIntensity, weight);
            if (newIntensity < intensity[next])
            {
                intensity[next] = newIntensity;
                pq.push({newIntensity, next});
            }
        }
    }
    
    answer[0] = 0;
    answer[1] = INT_MAX;
    
    sort(summits.begin(), summits.end());
    
    for (int summit : summits)
    {
        if (intensity[summit] < answer[1])
        {
            answer[0] = summit;
            answer[1] = intensity[summit];
        }
    }
    
    return answer;
}