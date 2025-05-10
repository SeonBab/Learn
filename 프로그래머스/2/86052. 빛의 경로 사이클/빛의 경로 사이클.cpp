#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    int rows = grid.size();
    int cols = grid[0].length();
    
    int dy[] = {-1, 0, 1, 0};
    int dx[] = {0, 1, 0, -1};
    
    vector<vector<vector<bool>>> visited(rows, vector<vector<bool>>(cols, vector<bool>(4, false)));
    
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                if (visited[i][j][k])
                {
                    continue;
                }
                
                int count = 0;
                int curY = i;
                int curX = j;
                int curDir = k;
                
                while (!visited[curY][curX][curDir])
                {
                    visited[curY][curX][curDir] = true;
                    ++count;
                    
                    if (grid[curY][curX] == 'L')
                    {
                        curDir = (curDir + 3) % 4;
                    }
                    else if (grid[curY][curX] == 'R')
                    {
                        curDir = (curDir + 1) % 4;
                    }
                    
                    curY = (curY + dy[curDir] + rows) % rows;
                    curX = (curX + dx[curDir] + cols) % cols;
                }
                
                if (count > 0)
                {
                    answer.push_back(count);
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}