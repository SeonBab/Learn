#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int getDistance(int startX, int startY, int x, int y)
{
    int dx = startX - x;
    int dy = startY - y;
    
    return dx * dx + dy * dy;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for (const auto& ball : balls)
    {
        int targetX = ball[0];
        int targetY = ball[1];
        int minDist = INT_MAX;
        
        if (!(startX == targetX && startY < targetY))
        {
            minDist = min(minDist, getDistance(startX, startY, targetX, n + n - targetY));
        }
        
        if (!(startX == targetX && startY > targetY))
        {
            minDist = min(minDist, getDistance(startX, startY, targetX, -targetY));
        }
        
        if (!(startY == targetY && startX > targetX))
        {
            minDist = min(minDist, getDistance(startX, startY, -targetX, targetY));
        }
        
        if (!(startY == targetY && startX < targetX))
        {
            minDist = min(minDist, getDistance(startX, startY, m + m - targetX, targetY));
        }
        
        answer.push_back(minDist);
    }
    
    return answer;
}