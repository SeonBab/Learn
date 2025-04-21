#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int solution(vector<string> board) {
    int h = board.size();
    int w = board[0].size();
    
    pair<int, int> start, goal;
    
    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            if (board[y][x] == 'R')
            {
                start = {y, x};
            }
            else if (board[y][x] == 'G')
            {
                goal = {y, x};
            }
        }
    }
    
    vector<vector<int>> visited(h, vector<int>(w, false));
    queue<tuple<int, int, int>> q;
    
    q.push({start.first, start.second, 0});
    visited[start.first][start.second] = true;
    
    while(!q.empty())
    {
        auto [y, x, count] = q.front();
        q.pop();
        
        if (y == goal.first && x == goal.second)
        {
            return count;
        }
        
        for (int i = 0; i < 4; ++i)
        {
            int ny = y;
            int nx = x;
            
            while(true)
            {
                int ty = ny + dy[i];
                int tx = nx + dx[i];
                
                if (ty < 0 || tx < 0 || ty >= h || tx >= w || board[ty][tx] == 'D')
                {
                    break;
                }
                
                ny = ty;
                nx = tx;
            }
            
            if (!visited[ny][nx])
            {
                visited[ny][nx] = true;
                q.push({ny, nx, count + 1});
            }
        }
    }
    
    return -1;
}