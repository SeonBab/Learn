#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long minX = x;
    long long minY = y;
    long long maxX = x;
    long long maxY = y;
    
    for(int i = queries.size() - 1; i >= 0; --i)
    {
        int command = queries[i][0];
        int dx = queries[i][1];
        
        if (command == 0)
        {
            if (minY > 0)
            {
                minY += dx;
            }
            maxY = min(maxY + dx, static_cast<long long>(m - 1));
            if (minY > m - 1)
            {
                return 0;
            }
        }
        else if (command == 1)
        {
            if (maxY < m -1)
            {
                maxY -= dx;
            }
            minY = max(minY - dx, 0LL);
            if (maxY < 0)
            {
                return 0;
            }
        }
        else if (command == 2)
        {
            if (minX > 0)
            {
                minX += dx;
            }
            maxX = min(maxX + dx, static_cast<long long>(n - 1));
            if (minX > n - 1)
            {
                return 0;
            }
        }
        else
        {
            if (maxX < n - 1)
            {
                maxX -= dx;
            }
            minX = max(minX - dx, 0LL);
            if (maxX < 0)
            {
                return 0;
            }
        }
    }
    
    return (maxX - minX + 1) * (maxY - minY + 1);
}