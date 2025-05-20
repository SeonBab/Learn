#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long left = 1;
    long long right = static_cast<long long>(*max_element(times.begin(), times.end())) * n;
    
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long total = 0;
        
        for (int time : times)
        {
            total += mid / time;
        }
        
        if (total >= n)
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    
    return answer;
}