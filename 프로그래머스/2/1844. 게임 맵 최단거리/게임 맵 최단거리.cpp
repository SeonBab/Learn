#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    
    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};
    
    int n = maps.size();
    int m = maps[0].size();
    
    queue<pair<int ,int>> q;
    q.push({0, 0});
    
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        int dist = maps[y][x];
        
        if (n - 1 == y && m - 1 == x)
        {
            return dist;
        }
        
        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || maps[ny][nx] == 0)
            {
                continue;
            }
            
            if (maps[ny][nx] == 1)
            {
                maps[ny][nx] = dist + 1;
                q.push({ny, nx});
            }
        }
    }
    
    return -1;
}