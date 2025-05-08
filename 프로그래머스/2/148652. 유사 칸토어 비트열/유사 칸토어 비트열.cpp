#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int countOnes(long long n, long long l, long long r)
{
    if (l > r)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    
    long long len = n / 5;
    long long count = 0;
    
    for (int i = 0; i < 5; ++i)
    {
        if (i == 2)
        {
            continue;
        }
        
        long long start = len * i;
        long long end = len * (i + 1) - 1;
        
        count += countOnes(len, max(l, start) - start, min(r, end) - start);
    }
    
    return count;
}

int solution(int n, long long l, long long r) {
    int answer = 0;
    
    answer = countOnes(pow(5, n), l - 1, r - 1);
    
    return answer;
}