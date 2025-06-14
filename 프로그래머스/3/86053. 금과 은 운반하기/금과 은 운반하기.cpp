#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

bool check(int a, int b, const vector<int>& g, const vector<int>& s, const vector<int>& w, const vector<int>& t, long long mid)
{
    long long total = 0;
    long long totalG = 0;
    long long totalS = 0;
    
    for (int i = 0; i < g.size(); ++i)
    {
        long long count = mid / (2LL * t[i]);
        
        if (mid % (2LL * t[i]) >= t[i])
        {
            ++count;
        }
        
        long long carry = min(count * w[i], static_cast<long long>(g[i]) + s[i]);
        total += carry;
        totalG += min(carry, static_cast<long long>(g[i]));
        totalS += min(carry, static_cast<long long>(s[i]));
    }
    
    return total >= a + b && totalG >= a && totalS >= b;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long min = 0;
    long long max = 4e14;
    
    while (min < max)
    {
        long long mid = min + (max - min) / 2;
        if (check(a, b, g, s, w, t, mid))
        {
            max = mid;
        }
        else
        {
            min = mid + 1;
        }
    }
    
    return max;
}