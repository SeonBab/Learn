#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;

int dx[4]{-1, 1, 0, 0};
int dy[4]{0, 0, -1, 1};

int dfs(const vector<string>& maps, vector<vector<bool>>& visited, int y, int x)
{
    visited[y][x] = true;
    int sumFood = static_cast<int>(maps[y][x]) - '0';
    
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny >= 0 && nx >= 0 &&
            ny < maps.size() && nx < maps[0].size() &&
            visited[ny][nx] == false && 
            maps[ny][nx] != 'X')
        {
            sumFood += dfs(maps, visited, ny, nx);
        }
    }
    
    return sumFood;
}

vector<int> solution(vector<string> maps) {
    
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
    
    for (int i = 0; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[0].size(); ++j)
        {
            if (visited[i][j] == false && maps[i][j] != 'X')
            {
                int islandFood = dfs(maps, visited, i, j);
                answer.push_back(islandFood);
            }
        }
    }
    
    if (answer.size() == 0)
    {
        return {-1};
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}