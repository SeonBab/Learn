#include <string>
#include <vector>
#include <set>
#include <climits>

using namespace std;

vector<string> solution(vector<vector<int>> line) {

    set<pair<long long , long long>> points;
    long long minX = LLONG_MAX;
    long long minY = LLONG_MAX;
    long long maxX = LLONG_MIN;
    long long maxY = LLONG_MIN;
    
    for (int i = 0; i < line.size(); ++i)
    {
        long long A1 = line[i][0];
        long long B1 = line[i][1];
        long long C1 = line[i][2];
        for (int j = 0; j < line.size(); ++j)
        {
            long long A2 = line[j][0];
            long long B2 = line[j][1];
            long long C2 = line[j][2];
            
            long long denominator = (A1 * B2) - (B1 * A2);
            
            if (denominator == 0)
            {
                continue;
            }
            
            long long xNumerator = (B1 * C2) - (C1 * B2);
            long long yNumerator = (C1 * A2) - (A1 * C2);
            
            if (xNumerator % denominator != 0 || yNumerator % denominator != 0)
            {
                continue;
            }
            
            long long x = xNumerator / denominator;
            long long y = yNumerator / denominator;
            
            points.insert({x, y});
            
            minX = min(minX, x);
            minY = min(minY, y);
            maxX = max(maxX, x);
            maxY = max(maxY, y);
        }
    }
    
    long long width = maxX - minX + 1;
    long long height = maxY - minY + 1;
    
    vector<string> answer(height, string(width, '.'));
    
    for (const auto& point : points)
    {
        long long x = point.first - minX;
        long long y = maxY - point.second;
        answer[y][x] = '*';
    }
    
    return answer;
}