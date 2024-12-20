#include <vector>

double solution(std::vector<int> arr) {
    double answer = 0;
    
    for (auto e : arr)
    {
        answer += e;
    }
    
    answer /= arr.size();
    
    return answer;
}