#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long index = left; index <= right; ++index)
    {
        long long x = index / n;
        long long y = index % n;
        
        answer.push_back(max(x, y) + 1);
    }
    
    return answer;
}