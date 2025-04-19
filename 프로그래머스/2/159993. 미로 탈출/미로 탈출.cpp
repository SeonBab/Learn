#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Point
{
    int x, y, dist;
};

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int bfs(const vector<string>& maps, pair<int, int> start, char target)
{
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    queue<Point> q;
    q.push({start.first, start.second, 0});
    visited[start.first][start.second] = true;
    
    while (!q.empty())
    {
        Point p = q.front();
        q.pop();
        
        if (maps[p.x][p.y] == target)
        {
            return p.dist;
        }
        
        for (int i = 0; i < 4; ++i)
        {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            
            if (nx >= 0 && ny >= 0 && nx < n && ny < m)
            {
                if (!visited[nx][ny] && maps[nx][ny] != 'X')
                {
                    visited[nx][ny] = true;
                    q.push( {nx, ny, p.dist + 1});
                }
            }
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    
    pair<int, int> start, lever, end;
    
    int n = maps.size();
    int m = maps[0].size();
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <m; ++j)
        {
            if (maps[i][j] == 'S')
            {
                start = {i, j};
            }
            else if (maps[i][j] == 'L')
            {
                lever = {i, j};
            }
            else if (maps[i][j] == 'E')
            {
                end = {i, j};
            }
        }
    }
    
    int toLever = bfs(maps, start, 'L');
    if (toLever == -1)
    {
        return -1;
    }
    
    int toEnd = bfs(maps, lever, 'E');
    if (toEnd == -1)
    {
        return -1;
    }
    
    answer = toLever + toEnd;
    
    return answer;
}