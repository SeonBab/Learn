#include <vector>

std::vector<long long> solution(int x, int n) {
    std::vector<long long> answer;
    
    for (int i = 1; i <= n; ++i)
    {
        answer.push_back(x * i);
    }
    
    return answer;
}