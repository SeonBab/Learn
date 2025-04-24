#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    for (int x = 1; x <= r2; ++x)
    {
        long long xSquared = (long long)x * x;
        
        long long maxY = (long long)floor(sqrt((long long)r2 * r2 - xSquared));
        
        long long minY = 0;
        if (xSquared < (long long)r1 * r1)
        {
            minY = (long long)ceil(sqrt((long long)r1 * r1 - xSquared));
        }
        
        if (maxY >= minY)
        {
            answer += (maxY - minY + 1);
        }
    }
    
    answer *= 4;
    
    return answer;
}