#include <vector>

int solution(std::vector<int> a, std::vector<int> b) {
    int answer = 0;
    
    for (int i = 0; i < a.size(); ++i)
    {
        answer += a[i] * b[i];
    }
    
    return answer;
}