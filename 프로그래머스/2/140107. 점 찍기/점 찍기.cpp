#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    for (long long a = 0; a <= d; a += k)
    {
        long long bSquared = static_cast<long long>(d) * d - a * a;
        answer += static_cast<long long>(sqrt(bSquared) / k) + 1;
    }
    
    return answer;
}