#include <vector>

using namespace std;

void dfs(vector<vector<int>>& computers, vector<bool>& visited, int n, int node)
{
    visited[node] = true;
    
    for (int i = 0; i < n; ++i)
    {
        if (computers[node][i] == 1 && !visited[i])
        {
            dfs(computers, visited, n, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            dfs(computers, visited, n, i);
            ++answer;
        }
    }
    
    return answer;
}