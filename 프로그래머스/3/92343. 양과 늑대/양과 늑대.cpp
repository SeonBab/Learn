#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int answer = 0;
vector<vector<int>> graph;

void dfs(const vector<int>& info, int currentNode, int sheep, int wolf, set<int> nextNodes)
{
    if (info[currentNode] == 0)
    {
        ++sheep;
    }
    else
    {
        ++wolf;
    }
    
    if (sheep <= wolf)
    {
        return;
    }
    
    answer = max(answer, sheep);
    
    nextNodes.erase(currentNode);
    for (int child : graph[currentNode])
    {
        nextNodes.insert(child);
    }
    
    for (int next : nextNodes)
    {
        dfs(info, next, sheep, wolf, nextNodes);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    graph.resize(info.size());
    
    for (auto edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
    }
    
    set<int> nextNodes = {0};
    dfs(info, 0, 0, 0, nextNodes);
    
    return answer;
}