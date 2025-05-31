#include <string>
#include <cmath>

using namespace std;

string answer = "";
int mapSize[2];
int targetLocation[2];
int countLimit;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char directionChar[] = {'d', 'l', 'r', 'u'};

void dfs(int x, int y, string path, int depth)
{
    if (!answer.empty())
    {
        return;
    }
    
    int remainDistance = abs(x - targetLocation[0]) + abs(y - targetLocation[1]);
    int remainMove = countLimit - depth;
    
    if (remainDistance > remainMove || (remainMove - remainDistance) % 2 != 0)
    {
        return;
    }
    
    if (depth == countLimit)
    {
        if (x == targetLocation[0] && y == targetLocation[1])
        {
            answer = path;
        }
        return;
    }
    
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx > 0 && nx <= mapSize[0] && ny > 0 && ny <= mapSize[1])
        {
            dfs(nx, ny, path + directionChar[i], depth + 1);
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    mapSize[0] = n;
    mapSize[1] = m;
    
    targetLocation[0] = r;
    targetLocation[1] = c;
    
    countLimit = k;
    
    int distance = abs(x - r) + abs(y - c);
    if (distance > k || (k - distance) % 2 == 1)
    {
        return "impossible";
    }
    
    dfs(x, y, "", 0);
    
    return answer;
}