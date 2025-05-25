#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    
    for (const auto& result : results)
    {
        int winner = result[0];
        int loser = result[1];
        
        graph[winner][loser] = 1;
        graph[loser][winner] = -1;
    }
    
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (graph[i][k] == 1 && graph[k][j] == 1)
                {
                    graph[i][j] = 1;
                    graph[j][i] = -1;
                }
                else if (graph[i][k] == -1 && graph[k][j] == -1)
                {
                    graph[i][j] = -1;
                    graph[j][i] = 1;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; ++i)
    {
        int known = 0;
        
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
            {
                continue;
            }
            
            if (graph[i][j] != 0)
            {
                ++known;
            }
        }
        
        if (known == n - 1)
        {
            ++answer;
        }
    }
    
    return answer;
}