#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> graph(n + 1);
    
    for (const auto& e : edge)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    vector<int> distance(n + 1, 0);
    vector<bool> visited(n + 1, false);
    
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        
        for (int next : graph[current])
        {
            if (!visited[next])
            {
                visited[next] = true;
                distance[next] = distance[current] + 1;
                q.push(next);
            }
        }
    }
    
    int maxDistance = *max_element(distance.begin(), distance.end());
    
    for (int e : distance)
    {
        if (e == maxDistance)
        {
            ++answer;
        }
    }
    
    return answer;
}