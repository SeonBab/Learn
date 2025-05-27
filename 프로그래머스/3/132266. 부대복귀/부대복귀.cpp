#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    vector<vector<int>> graph(n + 1);
    
    for (const auto& road : roads)
    {
        int a = road[0];
        int b = road[1];
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    vector<int> distance(n + 1, -1);
    
    queue<int> q;
    
    q.push(destination);
    distance[destination] = 0;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for (int next : graph[cur])
        {
            if (distance[next] == -1)
            {
                distance[next] = distance[cur] + 1;
                q.push(next);
            }
        }
    }
    
    for (int source : sources)
    {
        answer.push_back(distance[source]);
    }
    
    return answer;
}