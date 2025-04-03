#include <vector>
#include <queue>
#include <limits>

using namespace std;

vector<int> dijkstra(int N, vector<vector<pair<int, int>>>& graph, int start)
{
    vector<int> dist(N + 1, numeric_limits<int>::max());
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (cost > dist[node])
        {
            continue;
        }

        for (auto& [next, nextCost] : graph[node])
        {
            int newCost = cost + nextCost;

            if (newCost < dist[next])
            {
                dist[next] = newCost;
                pq.push({newCost, next});
            }
        }
    }
    
    return dist;
}

int solution(int N, vector<vector<int> > road, int K) {
    
    int answer = 0;
    
    vector<vector<pair<int, int>>> graph(N + 1);
    
    for(auto& e : road)
    {
        int a = e[0];
        int b = e[1];
        int weight = e[2];
        
        graph[a].push_back({b, weight});
        graph[b].push_back({a, weight});
    }

    vector<int> dist = dijkstra(N, graph, 1);

    for (int i = 1; i <= N; ++i)
    {
        if (dist[i] <= K)
        {
            ++answer;
        }
    }

    return answer;
}